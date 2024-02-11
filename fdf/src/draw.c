/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:42:10 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/11 19:17:51 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void autofocus(t_list *list, t_line *point)
{
	float zoom;

	zoom = list->data->zoom;
	while (point->x1proj > 400 && point->y1proj > 300)
	{
		zoom /= 0.99;
		point->x1proj = list->data->offsetx + (point->x1 - 0.5 * list->data->height * point->z1 * sqrt(3) / 2) * zoom;
		point->y1proj = list->data->offsety + (point->y1 - 0.5 * list->data->height * point->z1 * sqrt(3) / 2) * zoom;
	}
	list->data->zoom = zoom;
}

static int *fill_array(t_point point)
{
	int *s;

	s = malloc(sizeof(int) * 2);
	if (!s)
		ft_return_error("error during malloc");
	if (point.x1 < point.x2)
		s[0] = 1;
	else
		s[0] = -1;
	if (point.y1 < point.y2)
		s[1] = 1;
	else
		s[1] = -1;
	return (s);
}

static void bresenham(t_point point, t_data *data)
{
	int *s;
	int err;
	int e2;

	s = fill_array(point);
	err = point.dx - point.dy;
	// printf("err %d s0 %d s1 %d\n", err, s[0], s[1]);
	while ((point.x2 != point.x1 || point.y2 != point.y1) && s)
	{
		// printf("x1 %d y1 %d\n", point.x1, point.y1);
		my_mlx_pixel_put(data, point.x1, point.y1, 0x3E5622);
		e2 = 2 * err;
		if (e2 > -point.dy)
		{
			err -= point.dy;
			point.x1 += s[0];
		}
		if (e2 < point.dx)
		{
			err += point.dx;
			point.y1 += s[1];
		}
	}
	my_mlx_pixel_put(data, point.x1, point.y1, 0x3E5622);
	free(s);
}

static t_point calculpoint1(t_map *map, t_data *data, t_point point, t_input input)
{
	int tr[2];
	int temp[2];
	float *q;
	float *p;
	float result[2];

	temp[0] = map->x - input.abs / 2;
	temp[1] = map->y - input.ord / 2;
	q = f_rot(cos(data->mov->rotz / 2), 0, 0, sin(data->mov->rotz / 2));
	p = f_rot(0, temp[0], temp[1], 0);
	result[0] = p[0] * q[1] + p[1] * q[0] + p[2] * q[3] - p[3] * q[2];
	result[1] = p[0] * q[2] - p[1] * q[3] + p[2] * q[0] + p[3] * q[1];
	tr[0] = data->mov->offsetx;
	tr[1] = data->mov->offsety;
	point.x1 = roundf(tr[0] + (result[0] - data->mov->height * map->z * sqrt(3) / 2) * data->mov->zoom);
	point.y1 = roundf(tr[1] + (result[1] - data->mov->height * map->z * sqrt(3) / 2) * data->mov->zoom);
	return (point);
}

static void calculpoint2(t_map *map, t_data *data, t_point point, t_input input)
{
	int tr[2];
	int temp[2];
	float *q;
	float *p;
	float result[2];

	temp[0] = map->x - roundf(input.abs / 2);
	temp[1] = map->y - roundf(input.ord / 2);
	q = f_rot(cos(data->mov->rotz / 2), 0, 0, sin(data->mov->rotz / 2));
	p = f_rot(0, temp[0], temp[1], 0);
	result[0] = p[0] * q[1] + p[1] * q[0] + p[2] * q[3] - p[3] * q[2];
	result[1] = p[0] * q[2] - p[1] * q[3] + p[2] * q[0] + p[3] * q[1];
	tr[0] = data->mov->offsetx;
	tr[1] = data->mov->offsety;
	point.x2 = roundf(tr[0] + (result[0] - data->mov->height * map->z * sqrt(3) / 2) * data->mov->zoom);
	point.y2 = roundf(tr[1] + (result[1] - data->mov->height * map->z * sqrt(3) / 2) * data->mov->zoom);
	point.dx = abs(point.x2 - point.x1);
	point.dy = abs(point.y2 - point.y1);
	bresenham(point, data);
}

void ft_indicexyz(t_map ***map, t_input input, t_data *data)
{
	int i;
	int j;
	t_point point;

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
