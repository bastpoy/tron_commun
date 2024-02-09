/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_move1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:48:17 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/06 21:41:29 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	height_increase(t_list *list)
{
	list->data->height += 0.05;
	mlx_destroy_image(list->data->mlx_ptr, list->img->img);
	list->img->img = mlx_new_image(list->data->mlx_ptr, 1920, 1080);
	elevation(list);
	ft_line_xyprojtop1(list);
}

void	height_decrease(t_list *list)
{
	list->data->height -= 0.05;
	mlx_destroy_image(list->data->mlx_ptr, list->img->img);
	list->img->img = mlx_new_image(list->data->mlx_ptr, 1920, 1080);
	elevation(list);
	ft_line_xyprojtop1(list);
}

void	rot_anti(t_list *list)
{
	list->data->angle = PI / 100;
	mlx_destroy_image(list->data->mlx_ptr, list->img->img);
	list->img->img = mlx_new_image(list->data->mlx_ptr, 1920, 1080);
	rotationz(list);
	ft_line_xyprojtop1(list);
}

void	rot_hor(t_list *list)
{
	list->data->angle = -PI / 100;
	mlx_destroy_image(list->data->mlx_ptr, list->img->img);
	list->img->img = mlx_new_image(list->data->mlx_ptr, 1920, 1080);
	rotationz(list);
	ft_line_xyprojtop1(list);
}

void	zoom_increase(t_list *list)
{
	list->data->zoom /= 0.99;
	mlx_destroy_image(list->data->mlx_ptr, list->img->img);
	list->img->img = mlx_new_image(list->data->mlx_ptr, 1920, 1080);
	zoom(list);
	ft_line_xyprojtop1(list);
}
