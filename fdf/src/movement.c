/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:48:46 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/05 18:41:34 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	elevation(t_list *list)
{
	t_line	*point;
	float	zoom;
	float	height;
	int		tr[2];

	tr[0] = list->data->offsetx;
	tr[1] = list->data->offsety;
	zoom = list->data->zoom;
	height = list->data->height;
	point = list->ptrbegin;
	while (point)
	{
		point->x1proj = tr[0] + (point->x1 - height * point->z1 * sqrt(3) / 2)
			* zoom;
		point->y1proj = tr[1] + (point->y1 - height * point->z1 * sqrt(3) / 2)
			* zoom;
		point = point->next;
	}
}

void	zoom(t_list *list)
{
	t_line	*point;
	float	zoom;
	float	height;
	int		tr[2];

	tr[0] = list->data->offsetx;
	tr[1] = list->data->offsety;
	zoom = list->data->zoom;
	height = list->data->height;
	point = list->ptrbegin;
	while (point)
	{
		point->x1proj = tr[0] + (point->x1 - height * point->z1 * sqrt(3) / 2)
			* zoom;
		point->y1proj = tr[1] + (point->y1 - height * point->z1 * sqrt(3) / 2)
			* zoom;
		point = point->next;
	}
}

void	rotationz(t_list *list)
{
	t_line	*point;
	float	*q;
	float	*p;
	float	result[2];

	point = list->ptrbegin;
	while (point)
	{
		q = f_rot(cos(list->data->angle / 2), 0, 0, sin(list->data->angle / 2));
		p = f_rot(0, point->x1, point->y1, 0);
		if (!q || !p)
			list->err = 0;
		result[0] = p[0] * q[1] + p[1] * q[0] + p[2] * q[3] - p[3] * q[2];
		result[1] = p[0] * q[2] - p[1] * q[3] + p[2] * q[0] + p[3] * q[1];
		point->x1 = result[0];
		point->y1 = result[1];
		point->x1proj = list->data->offsetx + (point->x1 - list->data->height
				* point->z1 * sqrt(3) / 2) * list->data->zoom;
		point->y1proj = list->data->offsety + (point->y1 - list->data->height
				* point->z1 * sqrt(3) / 2) * list->data->zoom;
		point = point->next;
		free_float(q, p);
	}
}

void	translatex(t_list *list)
{
	t_line	*point;
	float	zoom;
	float	height;
	int		tr[2];

	tr[0] = list->data->offsetx;
	tr[1] = list->data->offsety;
	zoom = list->data->zoom;
	height = list->data->height;
	point = list->ptrbegin;
	while (point)
	{
		point->x1proj = tr[0] + (point->x1 - height * point->z1 * sqrt(3) / 2)
			* zoom;
		point->y1proj = tr[1] + (point->y1 - height * point->z1 * sqrt(3) / 2)
			* zoom;
		point = point->next;
	}
}

void	translatey(t_list *list)
{
	t_line	*point;
	float	zoom;
	float	height;
	int		tr[2];

	tr[0] = list->data->offsetx;
	tr[1] = list->data->offsety;
	zoom = list->data->zoom;
	height = list->data->height;
	point = list->ptrbegin;
	while (point)
	{
		point->x1proj = tr[0] + (point->x1 - height * point->z1 * sqrt(3) / 2)
			* zoom;
		point->y1proj = tr[1] + (point->y1 - height * point->z1 * sqrt(3) / 2)
			* zoom;
		point = point->next;
	}
}
