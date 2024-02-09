/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:41:55 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/08 18:23:45 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define PI 3.1416
# define WHITECOLOR 0xffffff
# define MAXCOLOR 0x523A37
# define MINCOLOR 0x3E5622

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "get_next_line.h"
# include "struct.h"
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

t_list	*ft_init_pointbegin(t_input input);
t_line	*ft_init_tline(t_list *list);
void	ft_free_entrystr(char **str);
int		ft_free_list(t_list *list);
void	free_float(float *q, float *p);
t_list	*ft_fill_struct(t_list *line, t_input input, char *entry);
t_line	*fill_tline(t_list *list, t_input input, t_line *line, int j);

void	ft_indicexyz(t_list *list, t_input input, t_line *line);
void	ft_line_xyprojtop1(t_list *list);
void	my_mlx_pixel_put(t_data *im, int x, int y, int color);
void	get_max_z(t_list *list, t_line *line);
int		ft_search_top(t_list *ptbegin, t_input input, t_line *entry);

float	*f_rot(float param1, float param2, float param3, float param4);

int		grad_color(t_line *p, t_parameter param);
void	color_to_point(t_list *list);

int		close_window(t_list *list);
void	ft_return_error(char *err_msg);
int		key_hook(int keycode, t_list *list);

void	elevation(t_list *list);
void	rotationz(t_list *list);
void	zoom(t_list *list);
void	translatex(t_list *list);
void	translatey(t_list *list);

void	height_increase(t_list *list);
void	height_decrease(t_list *list);
void	rot_anti(t_list *list);
void	rot_hor(t_list *list);
void	zoom_increase(t_list *list);
void	zoom_decrease(t_list *list);
void	translate_right(t_list *list);
void	translate_left(t_list *list);
void	translate_bot(t_list *list);
void	translate_top(t_list *list);

#endif