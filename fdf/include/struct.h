/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:09:50 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/12 11:46:34 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
#define STRUCT_H

typedef struct s_map
{
	int x;
	int y;
	int z;
	int color;
} t_map;

typedef struct s_input
{
	int abs;
	int ord;
} t_input;

typedef struct s_point
{
	int dx;
	int dy;
	int x1;
	int y1;
	int x2;
	int y2;
	int z1;
	int z2;
	int color;
} t_point;

typedef struct s_mov
{
	float height;
	int zoom;
	int rotz;
	int offsetx;
	int offsety;
} t_mov;

typedef struct s_data
{
	void *img;
	char *addr;
	void *mlx_ptr;
	void *mlx_win;
	int bits_per_pixel;
	int line_length;
	int endian;
	t_mov *mov;
	t_map ***map;
	t_input input;
} t_data;

typedef struct s_env
{
	void *mlx_ptr;
	void *mlx_win;
	float angle;
	float height;
	float zoom;
	int offsetx;
	int offsety;
} t_env;

typedef struct s_parameter
{
	int dx;
	int dy;
	int x1;
	int y1;
	int x2;
	int y2;
	int z;
	int color;
} t_parameter;

typedef struct s_line
{
	float x1;
	float y1;
	int z1;
	float x1proj;
	float y1proj;
	int color;
	int index;
	struct s_line *top;
	struct s_line *next;
} t_line;

typedef struct s_list
{
	t_line *ptrbegin;
	t_input input;
	t_env *data;
	t_data *img;
	int zmax;
} t_list;

#endif