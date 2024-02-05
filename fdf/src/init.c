/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:30:40 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/05 18:56:51 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static t_list	*init_data(t_list *list, t_input input)
{
	t_env	*data;

	data = malloc(sizeof(t_env));
	if (!data)
		return (0);
	data->angle = 0;
	data->height = 0.25;
	data->zoom = 1;
	data->offsetx = 1000;
	data->offsety = 500;
	data->mlx_ptr = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx_ptr, 1920, 1080, "Hello world");
	list->data = data;
	list->input = input;
	return (list);
}

t_list	*ft_init_pointbegin(t_input input)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (0);
	list->ptrbegin = NULL;
	list->data = NULL;
	list->zmax = 0;
	list->err = 1;
	list = init_data(list, input);
	return (list);
}

t_line	*ft_init_tline(t_list *list)
{
	t_line	*line;

	line = malloc(sizeof(t_line));
	if (!line)
	{
		list->err = 0;
	}
	line->x1 = 0;
	line->y1 = 0;
	line->x1proj = 0;
	line->y1proj = 0;
	line->z1 = 0;
	line->color = 0;
	line->index = -1;
	line->next = NULL;
	line->top = NULL;
	return (line);
}

float	*f_rot(float param1, float param2, float param3, float param4)
{
	float	*elem;

	elem = malloc(4 * sizeof(float));
	if (!elem)
		return (0);
	elem[0] = param1;
	elem[1] = param2;
	elem[2] = param3;
	elem[3] = param4;
	return (elem);
}
