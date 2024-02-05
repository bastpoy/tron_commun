/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:48:25 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/05 15:34:44 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	close_window(t_list *list)
{
	mlx_destroy_window(list->data->mlx_ptr, list->data->mlx_win);
	free(list->data);
	ft_free_list(list);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_list *list)
{
	if (keycode == 65307)
		close_window(list);
	if (keycode == 119)
		height_increase(list);
	if (keycode == 115)
		height_decrease(list);
	if (keycode == 100)
		rot_anti(list);
	if (keycode == 97)
		rot_hor(list);
	if (keycode == 114)
		zoom_increase(list);
	if (keycode == 102)
		zoom_decrease(list);
	if (keycode == 65363)
		translate_right(list);
	if (keycode == 65361)
		translate_left(list);
	if (keycode == 65364)
		translate_bot(list);
	if (keycode == 65362)
		translate_top(list);
	return (0);
}
