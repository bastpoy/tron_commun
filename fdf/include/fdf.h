/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:41:55 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/13 19:07:33 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define PI 3.1416
# define WHITECOLOR 0xffffff
# define MAXCOLOR 0x523A37
# define MINCOLOR 0x3E5622
# define WIDTH 1920
# define HEIGHT 1080
#define BUFFER 500000

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "get_next_line.h"
# include "struct.h"
# include <limits.h>
# include <math.h>
# include <stdlib.h>

t_data	*init_data(t_map ***map, t_input input);
int check_map(char *entry);
void	ft_free_entrystr(char **str);
void	free_ptrptrptr(char ***str);
void	free_map(t_map ***str);
void	free_float(float *q, float *p);
t_map	***ft_fill_struct(t_input input, char *entry);

void	ft_indicexyz(t_map ***map, t_input input, t_data *data);
void	autofocus(t_map ***map, t_input input, t_data *data);
t_point	calculpoint1(t_map *map, t_data *data, t_point point, t_input input);
void	calculpoint2(t_map *map, t_data *data, t_point point, t_input input);
void	my_mlx_pixel_put(t_data *im, int x, int y, int color);

float	*f_rot(float param1, float param2, float param3, float param4);
int		ft_hex_to_int(char *str);

int		close_window(t_data *data);
int		key_hook(int keycode, t_data *data);
int		grad_color(t_point point);

void	error_map(char *err_msg, t_map ***map);
void	ft_return_error(char *err_msg);
void	error_point(char *err_msg, t_map ***map, int max);
int		error_openfile(char *entry);

void	height_increase(t_data *data);
void	height_decrease(t_data *data);
void	zoom_increase(t_data *data);
void	zoom_decrease(t_data *data);
void	rot_anti(t_data *data);
void	rot_hor(t_data *data);
void	translate_right(t_data *data);
void	translate_left(t_data *data);
void	translate_bot(t_data *data);
void	translate_top(t_data *data);

#endif