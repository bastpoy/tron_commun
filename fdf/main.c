/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:19:58 by bpoyet            #+#    #+#             */
/*   Updated: 2024/01/26 16:56:10 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

int ft_get_abs(char *str)
{
    int count;

    count = 0;
    while (str)
    {
        if (*str == ' ')
            count++;
        str++;
    }
    count++;
    return (count);
}

void ft_free_entrystr(char **str)
{
    int i;

    i = 0;
    if (str)
    {
        while (str[i])
        {
            free(str[i]);
            i++;
        }
        free(str[i]);
        free(str);
    }
}

void ft_high_coef(t_data img, t_extremities point, t_parameter param)
{
    if (param.dy < 0)
        param.dy = -param.dy;
    if (param.dx < 0)
        param.dx = -param.dx;
    param.d = (2 * param.dx) - param.dy;
    while ((param.y <= point.yb && point.yb - point.ya > 0) ||
           (param.y >= point.yb && point.yb - point.ya < 0))
    {
        printf("pointy %d et x %d et d %d\n", param.y, param.x, param.d);
        if (param.d > 0)
        {
            param.d = param.d + 2 * (param.dx - param.dy);
            if (param.dx < 0)
                param.x = param.x - 1;
            else
                param.x = param.x + 1;
        }
        else
            param.d = param.d + (2 * param.dx);
        ft_mlx_pixel_put(&img, param.x, param.y, 16777215);
        if (point.yb - point.ya < 0)
            param.y = param.y - 1;
        else
            param.y = param.y + 1;
    }
}

void ft_low_coef(t_data img, t_extremities point, t_parameter param)
{
    if (param.dx < 0)
        param.dx = -param.dx;
    if (param.dy < 0)
        param.dy = -param.dy;
    param.d = (2 * param.dy) - (param.dx);
    while ((param.x <= point.xb && point.xb - point.xa > 0) ||
           (param.x >= point.xb && point.xb - point.xa < 0))
    {
        printf("pointx %d pointy %d et d %d\n", param.x, param.y, param.d);
        if (param.d > 0)
        {
            param.d = param.d + 2 * (param.dy - param.dx);
            if (param.dy < 0)
                param.y = param.y - 1;
            else
                param.y = param.y + 1;
        }
        else
            param.d = param.d + 2 * (param.dy);
        ft_mlx_pixel_put(&img, param.x, param.y, 16777215);
        if (point.xb - point.xa < 0)
        {
            param.x = param.x - 1;
        }
        else
            param.x = param.x + 1;
    }
}

void ft_line(void *mlx_ptr, void *mlx_win, t_data img, t_extremities point)
{
    t_parameter param;

    param.dx = point.xb - point.xa;
    param.dy = point.yb - point.ya;
    param.coef = ((float)(param.dy) / (float)(param.dx));
    param.x = point.xa;
    param.y = point.ya;
    printf("coef %f et x %d et xb %d\n", param.coef, param.x, point.xb);
    if ((param.coef <= 1 && param.coef > 0) || (param.coef >= -1 && param.coef < 0))
        ft_low_coef(img, point, param);
    else
        ft_high_coef(img, point, param);
    mlx_put_image_to_window(mlx_ptr, mlx_win, img.img, 0, 0);
}

void ft_high_coefxyproj(t_data img, t_line *line, t_parameter param)
{
    if (param.dy < 0)
        param.dy = -param.dy;
    if (param.dx < 0)
        param.dx = -param.dx;
    param.d = (2 * param.dx) - param.dy;
    while ((param.y <= line->y1proj && line->y1proj - line->behind->y1proj > 0) ||
           (param.y >= line->y1proj && line->y1proj - line->behind->y1proj < 0))
    {
        // printf(" highbeh pointy %d et x %d et j %d\n", param.y, param.x, line->index);
        if (param.d > 0)
        {
            param.d = param.d + 2 * (param.dx - param.dy);
            if (param.dx < 0)
                param.x = param.x - 1;
            else
                param.x = param.x + 1;
        }
        else
            param.d = param.d + (2 * param.dx);
        ft_mlx_pixel_put(&img, param.x, param.y, line->color);
        if (line->y1proj - line->behind->y1proj < 0)
            param.y = param.y - 1;
        else
            param.y = param.y + 1;
    }
}

void ft_high_coefxyproj1(t_data img, t_line *line, t_parameter param)
{
    printf("hightop\n");
    if (param.dy < 0)
        param.dy = -param.dy;
    if (param.dx < 0)
        param.dx = -param.dx;
    param.d = (2 * param.dx) - param.dy;
    while ((param.y <= line->y1proj && line->y1proj -line->top->y1proj > 0) ||
           (param.y >= line->y1proj && line->y1proj -line->top->y1proj < 0))
    {
        printf("pointy %d et x %d et j %d\n", param.y, param.x, line->index);
        if (param.d > 0)
        {
            param.d = param.d + 2 * (param.dx - param.dy);
            if (param.dx < 0)
                param.x = param.x - 1;
            else
                param.x = param.x + 1;
        }
        else
            param.d = param.d + (2 * param.dx);
        ft_mlx_pixel_put(&img, param.x, param.y, line->color);
        if (line->y1proj - line->top->y1proj < 0)
            param.y = param.y - 1;
        else
            param.y = param.y + 1;
    }
}

void ft_low_coefxyproj(t_data img, t_line *line, t_parameter param)
{
    (void)img;
    if (param.dx < 0)
        param.dx = -param.dx;
    if (param.dy < 0)
        param.dy = -param.dy;
    param.d = (2 * param.dy) - (param.dx);
    while ((param.x <= line->x1proj && line->x1proj - line->behind->x1proj > 0) ||
           (param.x >= line->x1proj && line->x1proj - line->behind->x1proj < 0))
    {
        // printf("behind low param x %d et proj %f\n", param.x, line->x1proj);
        if (param.d > 0)
        {
            param.d = param.d + 2 * (param.dy - param.dx);
            if (param.dy < 0)
                param.y = param.y - 1;
            else
                param.y = param.y + 1;
        }
        else
            param.d = param.d + 2 * (param.dy);
        ft_mlx_pixel_put(&img, param.x, param.y, line->color);
        if (line->x1proj - line->behind->x1proj < 0)
        {
            param.x = param.x - 1;
        }
        else
            param.x = param.x + 1;
    }
}

void ft_low_coefxyproj1(t_data img, t_line *line, t_parameter param)
{
    (void)img;
    if (param.dx < 0)
        param.dx = -param.dx;
    if (param.dy < 0)
        param.dy = -param.dy;
    param.d = (2 * param.dy) - (param.dx);
    while ((param.x <= line->x1proj && line->x1proj - line->top->x1proj > 0) ||
           (param.x >= line->x1proj && line->x1proj - line->top->x1proj < 0))
    {
        if (param.d > 0)
        {
            param.d = param.d + 2 * (param.dy - param.dx);
            if (param.dy < 0)
                param.y = param.y - 1;
            else
                param.y = param.y + 1;
        }
        else
            param.d = param.d + 2 * (param.dy);
        // printf("dans low paramx %d et behind x1proj %f paramy %d soustraction %f j %d\n", param.x, line->behind->x1proj, param.y, line->behind->x1proj - line->x1proj, line->index);
        ft_mlx_pixel_put(&img, param.x, param.y, line->color);
        if (line->x1proj - line->top->x1proj < 0)
        {
            param.x = param.x - 1;
        }
        else
            param.x = param.x + 1;
    }
}

void ft_line_xyproj(void *mlx_ptr, void *mlx_win, t_data img, t_list *list)
{
    t_line *line;
    t_parameter param;

    line = list->ptrbegin;
    while (line->index < 917)
    {
        if (line->behind)
        {
            printf("behind %d %f\n", line->index, line->behind->x1proj);
            param.dx = line->x1proj - line->behind->x1proj;
            param.dy = line->y1proj - line->behind->y1proj;

            param.coef = ((float)(param.dy) / (float)(param.dx));
            param.x = roundf(line->behind->x1proj);
            param.y = roundf(line->behind->y1proj);
            if ((param.coef <= 1 && param.coef > 0) ||
                (param.coef >= -1 && param.coef < 0))
                ft_low_coefxyproj(img, line, param);
            else
                ft_high_coefxyproj(img, line, param);
        }
        line = line->next;
    }
    mlx_put_image_to_window(mlx_ptr, mlx_win, img.img, 0, 0);
}

void ft_line_xyproj1(void *mlx_ptr, void *mlx_win, t_data img, t_list *list)
{
    t_line *line;
    t_parameter param;

    line = list->ptrbegin;
    while (line->index < 917)
    {
        if (line->top)
        {
            printf("top %d %f\n", line->index, line->top->x1proj);
            param.dx = line->x1proj - line->top->x1proj;
            param.dy = line->y1proj - line->top->y1proj;

            param.coef = ((float)(param.dy) / (float)(param.dx));
            param.x = roundf(line->top->x1proj);
            param.y = roundf(line->top->y1proj);
            // printf("%d %d\n", param.x, param.y);
            if ((param.coef <= 1 && param.coef > 0) ||
                (param.coef >= -1 && param.coef < 0))
                ft_low_coefxyproj1(img, line, param);
            else
                ft_high_coefxyproj1(img, line, param);
        }
        line = line->next;
    }
    mlx_put_image_to_window(mlx_ptr, mlx_win, img.img, 0, 0);
}

void ft_line_xyproj2(void *mlx_ptr, void *mlx_win, t_data img, t_list *list)
{
    t_line *line;
    float coef;
    int yzero;
    int x;
    int y;
    
    line = list->ptrbegin;
    while(line)
    {
        // printf("index %d\n", line->index);
        if(line->top)
        {
            printf("dans top %d\n", line->index);
            coef = (line->top->y1 / line->y1) / (line->top->x1 - line->x1);
            yzero = line-> y1 - (line->x1 * coef);
            x = line->x1;
            // printf("coef %f x %d", coef, x);
            while((x < line->top->x1 && coef > 0) ||
                (x > line->top->x1 && coef < 0))
            { //y = ax + b
                // printf("x %d", x);
                y = roundf(coef * x) + yzero ;
                ft_mlx_pixel_put(&img, x, y, line->color);
                if(coef < 0)
                    x--;
                else
                    x++;
            }
        }
        line = line->next;
    }
    mlx_put_image_to_window(mlx_ptr, mlx_win, img.img, 0, 0);
}

int main(void)
{
    void *mlx_ptr;
    void *mlx_win;
    t_data img;
    t_input input;
    t_list *list;
    int fd;

    fd = open("maps/test_maps/pyramide.fdf", O_RDONLY);
    list = ft_init_pointbegin();
    input = ft_get_length_width();
    printf("input abs %f input ord %f et total %f\n", input.abs, input.ord, input.abs * input.ord);
    // printf("de/ ltaabs %f deltaord %f", )

    mlx_ptr = mlx_init();
    mlx_win = mlx_new_window(mlx_ptr, 1920, 1080, "Hello world");
    img.img = mlx_new_image(mlx_ptr, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

    ft_fill_struct(list, input, fd);
    ft_line_xyproj(mlx_ptr, mlx_win, img, list);
    ft_line_xyproj1(mlx_ptr, mlx_win, img, list);
    ft_free_list(list);

    mlx_loop(mlx_ptr);
}
