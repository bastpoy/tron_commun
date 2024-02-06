/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:42:10 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/06 12:12:11 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_line	*fill_tline(t_list *list, t_input input, t_line *line, int j)
{
	line->index = j;
	ft_search_top(list, input, line);
	get_max_z(list, line);
	ft_indicexyz(list, input, line);
	return (line);
}

int	ft_search_top(t_list *list, t_input input, t_line *entry)
{
	t_line	*line;

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

void	get_max_z(t_list *list, t_line *line)
{
	if (line->z1 > list->zmax)
		list->zmax = line->z1;
}

void	autofocus(t_list *list, t_line *point)
{
	float	height;
	float	zoom;
	int		tr[2];

	tr[0] = list->data->offsetx;
	tr[1] = list->data->offsety;
	height = list->data->height;
	zoom = list->data->zoom;
	while (point->x1proj > 300 && point->y1proj > 200)
	{
		point->x1proj = tr[0] + (point->x1 - 0.5 * height * point->z1 * sqrt(3)
				/ 2) * zoom;
		point->y1proj = tr[1] + (point->y1 - 0.5 * height * point->z1 * sqrt(3)
				/ 2) * zoom;
		zoom /= 0.99;
	}
	if (zoom != list->data->zoom)
		zoom *= 0.99;
	list->data->zoom = zoom;
}

void	ft_indicexyz(t_list *list, t_input input, t_line *point)
{
	int		gap[2];
	float	x1origin;
	float	y1origin;
	int		tr[2];

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
	point->x1proj = tr[0] + (point->x1 - list->data->height * point->z1
			* sqrt(3) / 2) * list->data->zoom;
	point->y1proj = tr[1] + (point->y1 - list->data->height * point->z1
			* sqrt(3) / 2) * list->data->zoom;
	if (point->index == 1)
		autofocus(list, point);
}
