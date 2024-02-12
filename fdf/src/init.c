/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:30:40 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/12 12:32:33 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static t_list *init_dat(t_list *list, t_input input)
{
	list->data = malloc(sizeof(t_env));
	if (!list->data)
	{
		free(list);
		ft_return_error("cannot malloc");
	}
	list->data->angle = 0;
	list->data->height = 0.15;
	list->data->zoom = 2;
	list->data->offsetx = 1000;
	list->data->offsety = 500;
	list->data->mlx_ptr = mlx_init();
	list->data->mlx_win = mlx_new_window(list->data->mlx_ptr, 1920, 1080,
										 "FDF");
	list->input = input;
	return (list);
}

t_list *ft_init_pointbegin(t_input input)
{
	t_list *list;
	t_data *img;

	list = malloc(sizeof(t_list));
	img = malloc(sizeof(t_data));
	if (!img)
	{
		free(list);
		ft_return_error("cannot malloc");
	}
	if (!list)
	{
		free(img);
		ft_return_error("cannot malloc");
	}
	list->ptrbegin = NULL;
	list->data = NULL;
	list->zmax = 0;
	list = init_dat(list, input);
	img->img = mlx_new_image(list->data->mlx_ptr, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
								  &img->line_length, &img->endian);
	list->img = img;
	return (list);
}

float *f_rot(float param1, float param2, float param3, float param4)
{
	float *elem;

	elem = malloc(4 * sizeof(float));
	if (!elem)
		ft_return_error("cannot malloc");
	elem[0] = param1;
	elem[1] = param2;
	elem[2] = param3;
	elem[3] = param4;
	return (elem);
}

static t_mov *init_mov()
{
	t_mov *mov;
	mov = malloc(sizeof(t_mov));
	if (!mov)
		ft_return_error("Malloc Error");
	mov->height = 0.1;
	mov->zoom = 5;
	mov->rotz = 20;
	mov->offsetx = WIDTH / 2;
	mov->offsety = HEIGHT / 2;
	return (mov);
}

t_data *init_data(t_map ***map, t_input input)
{
	t_data *data;
	t_mov *mov;

	mov = init_mov();
	data = malloc(sizeof(t_data));
	if (!data)
		ft_return_error("Malloc Error");
	data->mlx_ptr = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx_ptr, 1920, 1080, "FDF");
	data->img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
								   &data->line_length, &data->endian);
	data->mov = mov;
	data->map = map;
	data->input = input;
	return (data);
}
