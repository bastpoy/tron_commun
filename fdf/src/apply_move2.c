/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_move2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:07:41 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/09 18:15:05 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void zoom_decrease(t_list *list)
{
    list->data->zoom *= 0.99;
    mlx_destroy_image(list->data->mlx_ptr, list->img->img);
    list->img->img = mlx_new_image(list->data->mlx_ptr, 1920, 1080);
    zoom(list);
    ft_line_xyprojtop1(list);
}

void translate_right(t_list *list)
{
    list->data->offsetx += 2;
    mlx_destroy_image(list->data->mlx_ptr, list->img->img);
    list->img->img = mlx_new_image(list->data->mlx_ptr, 1920, 1080);
    translatex(list);
    ft_line_xyprojtop1(list);
}

void translate_left(t_list *list)
{
    list->data->offsetx -= 2;
    mlx_destroy_image(list->data->mlx_ptr, list->img->img);
    list->img->img = mlx_new_image(list->data->mlx_ptr, 1920, 1080);
    translatex(list);
    ft_line_xyprojtop1(list);
}

void translate_bot(t_list *list)
{
    list->data->offsety += 2;
    mlx_destroy_image(list->data->mlx_ptr, list->img->img);
    list->img->img = mlx_new_image(list->data->mlx_ptr, 1920, 1080);
    translatey(list);
    ft_line_xyprojtop1(list);
}

void translate_top(t_list *list)
{
    list->data->offsety -= 2;
    mlx_destroy_image(list->data->mlx_ptr, list->img->img);
    list->img->img = mlx_new_image(list->data->mlx_ptr, 1920, 1080);
    translatey(list);
    ft_line_xyprojtop1(list);
}
