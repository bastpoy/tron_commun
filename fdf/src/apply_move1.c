/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_move1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:48:17 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/06 18:45:41 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	height_increase(t_list *list)
{
	list->data->height += 0.05;
	mlx_clear_window(list->data->mlx_ptr, list->data->mlx_win);
	elevation(list);
	ft_line_xyprojtop1(list, list->data);
}

void	height_decrease(t_list *list)
{
	list->data->height -= 0.05;
	mlx_clear_window(list->data->mlx_ptr, list->data->mlx_win);
	elevation(list);
	ft_line_xyprojtop1(list, list->data);
}

void	rot_anti(t_list *list)
{
	list->data->angle = PI / 100;
	mlx_clear_window(list->data->mlx_ptr, list->data->mlx_win);
	rotationz(list);
	ft_line_xyprojtop1(list, list->data);
}

void	rot_hor(t_list *list)
{
	list->data->angle = -PI / 100;
	mlx_clear_window(list->data->mlx_ptr, list->data->mlx_win);
	rotationz(list);
	ft_line_xyprojtop1(list, list->data);
}

void	zoom_increase(t_list *list)
{
	list->data->zoom /= 0.99;
	mlx_clear_window(list->data->mlx_ptr, list->data->mlx_win);
	zoom(list);
	ft_line_xyprojtop1(list, list->data);
}
