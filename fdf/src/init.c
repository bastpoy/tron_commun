/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:30:40 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/06 19:04:13 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static t_list	*init_data(t_list *list, t_input input)
{
	list->data = malloc(sizeof(t_env));
	if (!list->data)
		return (0);
	list->data->angle = 0;
	list->data->height = 0.25;
	list->data->zoom = 1;
	list->data->offsetx = 1000;
	list->data->offsety = 500;
	list->data->mlx_ptr = mlx_init();
	list->data->mlx_win = mlx_new_window(list->data->mlx_ptr, 1920, 1080,
			"FDF");
	list->input = input;
	return (list);
}

t_data *init_img(t_list *list)
{
	t_data *img;

	img = malloc(sizeof(t_data));
	if(!img)
	{
		list->err = 0;
		return(0);
	}
	img->img = mlx_new_image(list->data->mlx_ptr, 1920, 1080);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
								&img->endian);
	return(img);
}

t_list	*ft_init_pointbegin(t_input input)
{
	t_list	*list;
	t_data *img;
	
	list = malloc(sizeof(t_list));
	img = malloc(sizeof(t_data));
	if (!list || !img)
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
