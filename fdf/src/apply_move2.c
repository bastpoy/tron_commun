/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_move2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:07:41 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/05 15:35:05 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	zoom_decrease(t_list *list)
{
	list->data->zoom *= 0.99;
	mlx_clear_window(list->data->mlx_ptr, list->data->mlx_win);
	zoom(list);
	ft_line_xyprojtop1(list, list->data);
}

void	translate_right(t_list *list)
{
	list->data->offsetx += 1;
	mlx_clear_window(list->data->mlx_ptr, list->data->mlx_win);
	translatex(list);
	ft_line_xyprojtop1(list, list->data);
}

void	translate_left(t_list *list)
{
	list->data->offsetx -= 1;
	mlx_clear_window(list->data->mlx_ptr, list->data->mlx_win);
	translatex(list);
	ft_line_xyprojtop1(list, list->data);
}

void	translate_bot(t_list *list)
{
	list->data->offsety += 1;
	mlx_clear_window(list->data->mlx_ptr, list->data->mlx_win);
	translatey(list);
	ft_line_xyprojtop1(list, list->data);
}

void	translate_top(t_list *list)
{
	list->data->offsety -= 1;
	mlx_clear_window(list->data->mlx_ptr, list->data->mlx_win);
	translatey(list);
	ft_line_xyprojtop1(list, list->data);
}
