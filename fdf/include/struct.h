/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:09:50 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/13 15:07:45 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_map
{
	int		x;
	int		y;
	int		z;
	int		color;
}			t_map;

typedef struct s_input
{
	int		abs;
	int		ord;
}			t_input;

typedef struct s_point
{
	int		dx;
	int		dy;
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		z1;
	int		z2;
	int		x0;
	int		y0;
	int		color1;
	int		color2;
}			t_point;

typedef struct s_mov
{
	float	height;
	int		zoom;
	int		rotz;
	int		offsetx;
	int		offsety;
}			t_mov;

typedef struct s_data
{
	void	*img;
	char	*addr;
	void	*mlx_ptr;
	void	*mlx_win;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_mov	*mov;
	t_map	***map;
	t_input	input;
}			t_data;

#endif