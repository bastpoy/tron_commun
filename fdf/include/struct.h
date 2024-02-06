/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:09:50 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/06 18:49:33 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_env
{
	void			*mlx_ptr;
	void			*mlx_win;
	void			*img;
	float			angle;
	float			height;
	float			zoom;
	int				offsetx;
	int				offsety;
}					t_env;

typedef struct s_parameter
{
	int				dx;
	int				dy;
	int				x;
	int				y;
	int				x0;
	int				y0;
	int				z;
	int				color;
}					t_parameter;

typedef struct s_input
{
	int				abs;
	int				ord;
	int				total;
}					t_input;

typedef struct s_line
{
	float			x1;
	float			y1;
	int				z1;
	float			x1proj;
	float			y1proj;
	int				color;
	int				index;
	struct s_line	*top;
	struct s_line	*next;
}					t_line;

typedef struct s_list
{
	t_line			*ptrbegin;
	t_input			input;
	t_env			*data;
	t_data *img;
	int				zmax;
	int				err;
}					t_list;

#endif