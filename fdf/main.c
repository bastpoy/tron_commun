/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:19:58 by bpoyet            #+#    #+#             */
/*   Updated: 2024/01/23 17:45:55 by bpoyet           ###   ########.fr       */
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

int main(void)
{
    void *mlx_ptr;
    void *mlx_win;
    t_data img;
    // t_input input;
    // t_list *list;
    // int fd;

    // fd = open("maps/test_maps/pyramide.fdf", O_RDONLY);
    // list = ft_init_pointbegin();
    // input = ft_get_length_width();
    // printf("input abs %d input ord %d et total %d\n", input.abs, input.ord, input.abs * input.ord);

    // ft_fill_struct(list, input, fd);
    // ft_free_list(list);

    // int i = 1;

    // t_extremities line1 = ft_create_tline(800, 1600, 100, 600); // segment haut long
    // t_extremities line2 = ft_create_tline(380, 1180, 467.5, 967.5); // segment bas long
    // t_extremities line3 = ft_create_tline(800, 380, 100, 467.5); // segment gauche larg
    t_extremities line3 = ft_create_tline(100, 1000, 100, 300);
    // t_extremities line4 = ft_create_tline(1600, 1180, 600, 967.5);  // segment droite larg

    // printf("longueur %f et  largeur %f\n", ft_line_length(line1), ft_line_length(line3));
    // t_data img;

    mlx_ptr = mlx_init();
    mlx_win = mlx_new_window(mlx_ptr, 1920, 1080, "Hello world");
    img.img = mlx_new_image(mlx_ptr, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

    // ft_line(mlx_ptr, mlx_win, img, line1);
    // ft_line(mlx_ptr, mlx_win, img, line2);
    ft_line(mlx_ptr, mlx_win, img, line3);
    // ft_line(mlx_ptr, mlx_win, img, line4);
    // ft_tline(mlx_ptr, mlx_win, img, list);

    // while (i <= input.ord)
    // {
    //     ft_line(mlx_ptr, mlx_win, img, ft_create_line(line3, ft_line_length(line3) * i / input.ord, line1, ft_line_length(line1)));
    //     i++;
    // }
    // i = 1;
    // while (i <= input.abs)
    // {
    //     ft_line(mlx_ptr, mlx_win, img, ft_create_line(line1, ft_line_length(line1) * i / input.abs, line3, ft_line_length(line3)));
    //     i++;
    // }

    mlx_loop(mlx_ptr);
}
