/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_move2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:07:41 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/11 17:42:05 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void translate_right(t_data *data)
{
    data->mov->offsetx += 10;
    mlx_destroy_image(data->mlx_ptr, data->img);
    data->img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
    data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
                                   &data->line_length, &data->endian);
    ft_indicexyz(data->map, data->input, data);
}

void translate_left(t_data *data)
{
    data->mov->offsetx -= 10;
    mlx_destroy_image(data->mlx_ptr, data->img);
    data->img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
    data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
                                   &data->line_length, &data->endian);
    ft_indicexyz(data->map, data->input, data);
}

void translate_bot(t_data *data)
{
    data->mov->offsety += 10;
    mlx_destroy_image(data->mlx_ptr, data->img);
    data->img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
    data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
                                   &data->line_length, &data->endian);
    ft_indicexyz(data->map, data->input, data);
}

void translate_top(t_data *data)
{
    data->mov->offsety -= 10;
    mlx_destroy_image(data->mlx_ptr, data->img);
    data->img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
    data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
                                   &data->line_length, &data->endian);
    ft_indicexyz(data->map, data->input, data);
}
