/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:19:58 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/02 19:05:05 by bpoyet           ###   ########.fr       */
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

t_list *init_data(t_list *list, t_input input)
{
    t_env *data;

    data = malloc(sizeof(t_env));
    data->angle = 0;
    data->height = 1;
    data->zoom = 1;
    data->mlx_ptr = mlx_init();
    data->mlx_win = mlx_new_window(data->mlx_ptr, 1920, 1080, "Hello world");
    list->data = data;
    list->input = input;
    return(list);
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

void ft_line_xyprojtop1(t_list *list, t_env *data, t_input input)
{
    t_line *point;
    t_parameter param;
    (void)input;

    point = list->ptrbegin;
    while (point->index < input.abs * input.ord)
    {
        // printf("indice %d\n", point->index);
        if (point->top)
        {
            // printf("top index %d x1 %f x1top %f y1 %f y1top %f et coef %f\n", point->index, point->x1proj, point->top->x1proj, point->y1proj, point->top->y1proj, point->z1);
            param.dx = fabs(roundf(point->x1proj) - roundf(point->top->x1proj));
            param.dy = fabs(roundf(point->y1proj) - roundf(point->top->y1proj));
            param.x = roundf(point->top->x1proj);
            param.y = roundf(point->top->y1proj);
            ft_bresenham(point, param, data);
        }
        if (point->behind)
        {
            // printf("behind index %d x1 %f x1top %f y1 %f y1top %f et coef %f\n", point->index, point->x1proj, point->behind->x1proj, point->y1proj, point->behind->y1proj, point->z1);
            param.dx = fabs(roundf(point->x1proj) - roundf(point->behind->x1proj));
            param.dy = fabs(roundf(point->y1proj) - roundf(point->behind->y1proj));
            param.x = roundf(point->behind->x1proj);
            param.y = roundf(point->behind->y1proj);
            ft_bresenham(point, param, data);
        }
        point = point->next;
    }
}

int key_hook(int keycode, t_list *list)
{
    // printf("%d\n", keycode);
    if (keycode == 65307)
    {
        mlx_destroy_window(list->data->mlx_ptr, list->data->mlx_win);
        exit(0);
    }
    if (keycode == 119) // top arrow heigh++
    {
        list->data->height += 0.05;
        mlx_clear_window(list->data->mlx_ptr, list->data->mlx_win);
        elevation(list, list->data);
        ft_line_xyprojtop1(list, list->data, list->input);
    }
    if (keycode == 115) // bot arrow height --
    {
        list->data->height -= 0.05;
        mlx_clear_window(list->data->mlx_ptr, list->data->mlx_win);
        elevation(list, list->data);
        ft_line_xyprojtop1(list, list->data, list->input);
    }
    if (keycode == 100) // left arrow z rotation anti horaire
    {
        list->data->angle = PI / 100;
        mlx_clear_window(list->data->mlx_ptr, list->data->mlx_win);
        rotationz(list, list->data);
        ft_line_xyprojtop1(list, list->data, list->input);
    }
    if (keycode == 97) // right arrow z rotation horaire
    {
        list->data->angle = -PI / 100;
        mlx_clear_window(list->data->mlx_ptr, list->data->mlx_win);
        rotationz(list, list->data);
        ft_line_xyprojtop1(list, list->data, list->input);
    }
    if ( keycode == 114) // zoom +
    {
        list->data->zoom /= 0.99;
        mlx_clear_window(list->data->mlx_ptr, list->data->mlx_win);
        zoom(list, list->data);
        ft_line_xyprojtop1(list, list->data, list->input);
    }
    if (keycode == 102) // zoom -
    {
        list->data->zoom *= 0.99;
        mlx_clear_window(list->data->mlx_ptr, list->data->mlx_win);
        zoom(list, list->data);
        ft_line_xyprojtop1(list, list->data, list->input);
    }
    return (0);
}

int main(int argc, char ** argv)
{
    t_input input;
    t_list *list;

    if (argc == 2)
    {
        input = ft_get_length_width(argv[1]);
        list = ft_init_pointbegin();
        list = init_data(list, input);

        printf("input abs %d input ord %d et total %d\n", input.abs, input.ord, input.total);
        ft_fill_struct(list, input, argv[1]);
        ft_line_xyprojtop1(list, list->data, input);
        mlx_hook(list->data->mlx_win, KeyPress, KeyPressMask, key_hook, (void*)list);    
        mlx_loop(list->data->mlx_ptr);
        ft_free_list(list);
    }
    return (0);
}
