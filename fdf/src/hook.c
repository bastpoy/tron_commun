/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:48:25 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/13 14:21:19 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	close_window(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	free(data->mov);
	free(data->mlx_ptr);
	free(data);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
		close_window(data);
	if (keycode == 119 || keycode == 122)
		height_increase(data);
	if (keycode == 115)
		height_decrease(data);
	if (keycode == 114)
		zoom_increase(data);
	if (keycode == 102)
		zoom_decrease(data);
	if (keycode == 65363)
		translate_right(data);
	if (keycode == 65361)
		translate_left(data);
	if (keycode == 65364)
		translate_bot(data);
	if (keycode == 65362)
		translate_top(data);
	if (keycode == 100)
		rot_anti(data);
	if (keycode == 97 || keycode == 113)
		rot_hor(data);
	return (0);
}
