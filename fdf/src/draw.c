/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:42:10 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/13 14:50:36 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	fill_array(int *s1, int *s2, t_point point)
{
	if (point.x1 < point.x2)
		*s1 = 1;
	else
		*s1 = -1;
	if (point.y1 < point.y2)
		*s2 = 1;
	else
		*s2 = -1;
}

static void	bresenham(t_point point, t_data *data)
{
	int	s1;
	int	s2;
	int	err;
	int	e2;

	fill_array(&s1, &s2, point);
	err = point.dx - point.dy;
	while (point.x2 != point.x1 || point.y2 != point.y1)
	{
		my_mlx_pixel_put(data, point.x1, point.y1, grad_color(point));
		e2 = 2 * err;
		if (e2 > -point.dy)
		{
			err -= point.dy;
			point.x1 += s1;
		}
		if (e2 < point.dx)
		{
			err += point.dx;
			point.y1 += s2;
		}
	}
	my_mlx_pixel_put(data, point.x1, point.y1, grad_color(point));
}

t_point	calculpoint1(t_map *map, t_data *data, t_point point, t_input input)
{
	float	result[2];

	result[0] = (map->x - input.abs / 2) * cos(data->mov->rotz * 0.0175)
		- (map->y - input.ord / 2) * sin(data->mov->rotz * 0.0175);
	result[1] = (map->x - input.abs / 2) * sin(data->mov->rotz * 0.0175)
		+ (map->y - input.ord / 2) * cos(data->mov->rotz * 0.0175);
	point.x1 = data->mov->offsetx + (result[0] - data->mov->height * map->z)
		* data->mov->zoom;
	point.y1 = data->mov->offsety + (result[1] - data->mov->height * map->z)
		* data->mov->zoom;
	point.z1 = map->z;
	point.color1 = map->color;
	point.x0 = point.x1;
	point.y0 = point.y1;
	return (point);
}

void	calculpoint2(t_map *map, t_data *data, t_point point, t_input input)
{
	float	result[2];

	result[0] = (map->x - input.abs / 2) * cos(data->mov->rotz * 0.0175)
		- (map->y - input.ord / 2) * sin(data->mov->rotz * 0.0175);
	result[1] = (map->x - input.abs / 2) * sin(data->mov->rotz * 0.0175)
		+ (map->y - input.ord / 2) * cos(data->mov->rotz * 0.0175);
	point.x2 = data->mov->offsetx + (result[0] - data->mov->height * map->z)
		* data->mov->zoom;
	point.y2 = data->mov->offsety + (result[1] - data->mov->height * map->z)
		* data->mov->zoom;
	point.dx = abs(point.x2 - point.x1);
	point.dy = abs(point.y2 - point.y1);
	point.z2 = map->z;
	point.color2 = map->color;
	bresenham(point, data);
}

void	ft_indicexyz(t_map ***map, t_input input, t_data *data)
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
