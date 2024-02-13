/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autofocus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:08:23 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/13 15:04:28 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static t_point	resize(t_map *map, t_data *data, t_point point, t_input input)
{
	if (point.x1 > 400 && point.x1 > 300)
	{
		while (point.x1 > 400 && point.y1 > 300)
		{
			data->mov->zoom += 1;
			point = calculpoint1(map, data, point, input);
		}
	}
	else
	{
		while (point.x1 < 400 && point.y1 < 300)
		{
			data->mov->zoom -= 1;
			point = calculpoint1(map, data, point, input);
		}
	}
	return (point);
}

void	autofocus(t_map ***map, t_input input, t_data *data)
{
	int		i;
	int		j;
	t_point	point;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			point = calculpoint1(map[i][j], data, point, input);
			if (i == 0 && j == 0)
				point = resize(map[i][j], data, point, input);
			if (i + 1 < input.ord)
				calculpoint2(map[i + 1][j], data, point, input);
			if (j + 1 < input.abs)
				calculpoint2(map[i][j + 1], data, point, input);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, 0, 0);
}
