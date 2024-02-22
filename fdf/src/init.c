/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:30:40 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/13 19:38:42 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

float	*f_rot(float param1, float param2, float param3, float param4)
{
	float	*elem;

	elem = malloc(4 * sizeof(float));
	if (!elem)
		ft_return_error("Malloc Error\n");
	elem[0] = param1;
	elem[1] = param2;
	elem[2] = param3;
	elem[3] = param4;
	return (elem);
}

static t_mov	*init_mov(void)
{
	t_mov	*mov;

	mov = malloc(sizeof(t_mov));
	if (!mov)
		ft_return_error("Malloc Error\n");
	mov->height = 0.1;
	mov->zoom = 5;
	mov->rotz = 20;
	mov->offsetx = WIDTH / 2;
	mov->offsety = HEIGHT / 2;
	return (mov);
}

t_data	*init_data(t_map ***map, t_input input)
{
	t_data	*data;
	t_mov	*mov;

	mov = init_mov();
	data = malloc(sizeof(t_data));
	if (!data)
		ft_return_error("Malloc Error\n");
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

int check_map(char *entry)
{
    int fd;
    char *str;
    int bytesread;

    str = malloc(sizeof(char) * BUFFER);
    if(!str)
        exit(1);
    fd = open(entry, O_RDONLY);
    bytesread = read(fd,str,BUFFER);
    if(bytesread == BUFFER || bytesread == 0) {
        free(str);
        ft_return_error("data error\n");
    }

    free(str);
    return(0);
}