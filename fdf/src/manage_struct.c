/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:42:10 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/10 23:55:55 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_line *fill_tline(t_list *list, t_input input, t_line *line, int j)
{
	line->index = j;
	// ft_search_top(list, input, line);
	get_max_z(list, line);
	ft_indicexyz(list, input, line);
	return (line);
}

int ft_search_top(t_list *list, t_input input, t_line *entry)
{
	t_line *line;

	line = list->ptrbegin;
	while (line != NULL)
	{
		if (line->index == entry->index - input.abs)
		{
			entry->top = line;
			return (1);
		}
		line = line->next;
	}
	entry->top = NULL;
	return (0);
}

void get_max_z(t_list *list, t_line *line)
{
	if (line->z1 > list->zmax)
		list->zmax = line->z1;
}

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

void ft_indicexyz(t_list ***map, t_input input, t_line *point)
{
	int gap[2];
	float x1origin;
	float y1origin;
	int tr[2];

	tr[0] = list->data->offsetx;
	tr[1] = list->data->offsety;
	if (point->index % input.abs != 0)
		x1origin = (point->index % input.abs) - 1;
	else
		x1origin = input.abs - 1;
	y1origin = (point->index - 1) / input.abs;
	gap[0] = input.abs / 2;
	gap[1] = input.ord / 2;
	x1origin = x1origin - gap[0];
	y1origin = y1origin - gap[1];
	point->x1 = x1origin * cos(PI / 6) - y1origin * sin(PI / 6);
	point->y1 = x1origin * sin(PI / 6) + y1origin * cos(PI / 6);
	point->x1proj = tr[0] + (point->x1 - list->data->height * point->z1 * sqrt(3) / 2) * list->data->zoom;
	point->y1proj = tr[1] + (point->y1 - list->data->height * point->z1 * sqrt(3) / 2) * list->data->zoom;
	if (point->index == 1)
		autofocus(list, point);
}

// mes fonctions
// mes fonctions
// mes fonctions
// mes fonctions

static int *fill_array(t_point point)
{
	int *s;

	s = malloc(sizeof(int) * 2);
	if (!s)
		ft_return_error("error during malloc");
	if (point.x2 < point.x1)
		s[0] = 1;
	else
		s[0] = -1;
	if (point.y2 < point.y1)
		s[1] = 1;
	else
		s[1] = -1;
	return (s);
}

static void bresenham(t_point point)
{
	int *s;
	int err;
	int e2;

	s = fill_array(point);
	err = point.dx - point.dy;
	while ((point.x2 != point.x1 || point.y2 != point.y1) && s)
	{
		my_mlx_pixel_put(list->img, point.x1, point.y1, 0x3E5622);
		e2 = 2 * err;
		if (e2 > -param.dy)
		{
			err -= param.dy;
			param.x += s[0];
		}
		if (e2 < param.dx)
		{
			err += param.dx;
			param.y += s[1];
		}
	}
	my_mlx_pixel_put(list->img, param.x, param.y, line->color);
	free(s);
}

void ft_indicexyz(t_map ***map, t_input input, t_mov *mov)
{
	int gap[2];
	int tr[2];
	int i;
	int j;
	t_point point;

	i = 0;
	tr[0] = WIDTH / 2;
	tr[1] = HEIGHT / 2;
	gap[0] = input.abs / 2;
	gap[1] = input.ord / 2;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			point.x1 = map[i][j]->x * cos(PI / 6) - map[i][j]->y * sin(PI / 6);
			point.y1 = map[i][j]->x * sin(PI / 6) - map[i][j]->y * cos(PI / 6);
			point.x1 = tr[0] + (point.x1 - mov->height * map[i][j]->z * sqrt(3) / 2) * mov->zoom;
			point.y1 = tr[1] + (point.y1 - mov->height * map[i][j]->z * sqrt(3) / 2) * mov->zoom;
			if (i + 1 < input.ord)
			{
				point.x2 = map[i + 1][j]->x * cos(PI / 6) - map[i + 1][j]->y * sin(PI / 6);
				point.y2 = map[i + 1][j]->x * sin(PI / 6) - map[i + 1][j]->y * cos(PI / 6);
				point.dx = point.x2 - point.x1;
				point.dy = point.y2 - point.y1;
				ft_bresenham()
			}
			if (j + 1 < input.abs)
			{
				point.x2 = map[i][j + 1]->x * cos(PI / 6) - map[i][j + 1]->y * sin(PI / 6);
				point.y2 = map[i][j + 1]->x * sin(PI / 6) - map[i][j + 1]->y * cos(PI / 6);
				point.dx = point.x2 - point.x1;
				point.dy = point.y2 - point.y1;
			}
			j++;
		}
		i++;
	}
}
