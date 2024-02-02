/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:19:58 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/02 01:04:18 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void ft_bresenham(t_line *line, t_parameter param, t_env *data)
{
    int sx;
    int sy;
    int err;
    int e2;

    sx = param.x < line->x1proj ? 1 : -1;
    sy = param.y < line->y1proj ? 1 : -1;
    err = param.dx - param.dy;
    while ((int)roundf(line->x1proj) != param.x || (int)roundf(line->y1proj) != param.y)
    {
        mlx_pixel_put(data->mlx_ptr, data->mlx_win, param.x, param.y, line->color);
        e2 = 2 * err;
        if (e2 > -param.dy)
        {
            err -= param.dy;
            param.x += sx;
        }
        if (e2 < param.dx)
        {
            err += param.dx;
            param.y += sy;
        }
        // printf("param.x %d, line->x1 %d, param.y %d line->y1 %d \n", param.x, (int)roundf(line->x1proj), param.y, (int)roundf(line->y1proj));
    }
    mlx_pixel_put(data->mlx_ptr, data->mlx_win, param.x, param.y, line->color);
}

void ft_line_xyprojtop1(t_list *list, t_env *data)
{
    t_line *line;
    t_parameter param;

    line = list->ptrbegin;
    printf("line %p\n", list);
    while (line->index < 209)
    {
        if (line->top)
        {
            // printf("top index %d x1 %f x1top %f y1 %f y1top %f et coef %f\n", line->index, line->x1proj, line->top->x1proj, line->y1proj, line->top->y1proj, line->z1);
            param.dx = fabs(roundf(line->x1proj) - roundf(line->top->x1proj));
            param.dy = fabs(roundf(line->y1proj) - roundf(line->top->y1proj));
            param.x = roundf(line->top->x1proj);
            param.y = roundf(line->top->y1proj);
            ft_bresenham(line, param, data);
        }
        if (line->behind)
        {
            // printf("behind index %d x1 %f x1top %f y1 %f y1top %f et coef %f\n", line->index, line->x1proj, line->behind->x1proj, line->y1proj, line->behind->y1proj, line->z1);
            param.dx = fabs(roundf(line->x1proj) - roundf(line->behind->x1proj));
            param.dy = fabs(roundf(line->y1proj) - roundf(line->behind->y1proj));
            param.x = roundf(line->behind->x1proj);
            param.y = roundf(line->behind->y1proj);
            ft_bresenham(line, param, data);
        }
        line = line->next;
    }
}

// void ft_line_xyprojbeh1(t_list *list, t_win data)
// {
//     t_line *line;
//     t_parameter param;

//     line = list->ptrbegin;
//     while (line->index < 209)
//     {
//         if (line->behind)
//         {
//             printf("behind index %d x1 %f x1top %f y1 %f y1top %f et coef %f\n", line->index, line->x1proj, line->behind->x1proj, line->y1proj, line->behind->y1proj, line->z1);
//             param.dx = fabs(roundf(line->x1proj) - roundf(line->behind->x1proj));
//             param.dy = fabs(roundf(line->y1proj) - roundf(line->behind->y1proj));
//             param.x = roundf(line->behind->x1proj);
//             param.y = roundf(line->behind->y1proj);
//             ft_bresenham(line, param, data);
//         }
//         line = line->next;
//     }
// }

int key_hook(int keycode, t_list *list)
{
    printf("%d\n", keycode);
    printf("re");
    if (keycode == 65307)
    {
        printf("je quitte la fenetre\n");
        mlx_destroy_window(list->data->mlx_ptr, list->data->mlx_win);
        exit(0);
    }
    if (keycode == 122) // fleche haut
    {
        list->data->height += 0.05;
        mlx_clear_window(list->data->mlx_ptr, list->data->mlx_win);
        change_height(list, list->data);
        ft_line_xyprojtop1(list, list->data);
    }
    if (keycode == 115) // fleche bas
    {
        list->data->height -= 0.05;
        mlx_clear_window(list->data->mlx_ptr, list->data->mlx_win);
        change_height(list, list->data);
        ft_line_xyprojtop1(list, list->data);
    }
    return (0);
}

int main(void)
{
    t_env *data;
    t_input input;
    t_list *list;

    list = ft_init_pointbegin();
    input = ft_get_length_width();
    printf("input abs %d input ord %d et total %d\n", input.abs, input.ord, input.abs * input.ord);

    data = malloc(sizeof(t_env));
    data->angle = 0;
    data->height = 1;
    data->mlx_ptr = mlx_init();
    data->mlx_win = mlx_new_window(data->mlx_ptr, 1920, 1080, "Hello world");
    list->data = data;

    ft_fill_struct(list, input);
    ft_line_xyprojtop1(list, data);
    mlx_key_hook(data->mlx_win, key_hook, list);
    mlx_loop(data->mlx_ptr);
    ft_free_list(list);
}
