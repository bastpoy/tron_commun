/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:41:55 by bpoyet            #+#    #+#             */
/*   Updated: 2024/01/12 19:06:20 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF
#define FDF
#define COEFX 0.625
#define COEFY -0.875

#include "minilibx-linux/mlx.h"
#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

typedef struct s_data
{
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
} t_data;

typedef struct s_line
{
    double xa;
    double xb;
    double ya;
    double yb;
} t_line;

typedef struct s_input
{
    int abs;
    int ord;
} t_input;

t_line ft_create_tline(double xa, double xb, double ya, double yb);
double ft_line_length(t_line line);
t_line ft_create_line(t_line line, double length, t_line line2, double length2);
void ft_line(void *mlx_ptr, void *mlx_win, t_data img, t_line point);
size_t ft_strlen_space_backn(const char *str);
t_input ft_get_length_width();
int **ft_fill_entry_num(t_input input);
int ***ft_malloc_array(t_input input);
char	**ft_split(char const *s, char c);
char **ft_input_str_space();

#endif