/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:36:00 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/13 15:01:34 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static float	get_dst(int start, int end, int current)
{
	int	place;
	int	distance;

	place = current - start;
	distance = end - start;
	if (distance == 0)
		return (1);
	else
		return ((float)place / (float)distance);
}

static int	get_pos_gradient(int start, int end, float pos)
{
	float	t;

	t = pos * pos * (3 - 2 * pos);
	return ((int)((1 - t) * start + t * end));
}

int	grad_color(t_point point)
{
	float	pos;
	int		red;
	int		green;
	int		blue;

	if (point.z1 == point.z2)
		return (point.color1);
	if (point.dx > point.dy)
		pos = get_dst(point.x0, point.x2, point.x1);
	else
		pos = get_dst(point.y0, point.y2, point.y1);
	red = get_pos_gradient((point.color1 >> 16) & 0xFF,
			(point.color2 >> 16) & 0xFF, pos);
	green = get_pos_gradient((point.color1 >> 8) & 0xFF,
			(point.color2 >> 8) & 0xFF, pos);
	blue = get_pos_gradient(point.color1 & 0xFF, point.color2 & 0xFF, pos);
	return ((red << 16) | (green << 8) | blue);
}
