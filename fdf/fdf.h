/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:41:55 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/04 23:34:40 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF
#define FDF
#define PI 3.1416
#define TETA PI / 6
#define WHITECOLOR 0xffffff
#define MAXCOLOR 0x009432
#define MINCOLOR 0xf79f1f

#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"
#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <limits.h>

typedef struct s_env
{
    void *mlx_ptr;
    void *mlx_win;
    void *img;
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
    int x;
    int y;
    int x0;
    int y0;
    int z;
    int color;
} t_parameter;

typedef struct s_input
{
    int abs;
    int ord;
    int total;
} t_input;

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
    int zmax;
} t_list;

t_list *ft_init_pointbegin();
t_list *ft_fill_struct(t_list *line, t_input input, char *entry);
t_input ft_get_length_width(char *entry);
t_line *ft_input_str_coma(char *str, t_line *line);
t_line *ft_init_tline();
size_t ft_strlen_space_backn(const char *str);
t_list *init_data(t_list *list, t_input input);
void ft_free_entrystr(char **str);
void ft_read_tline(t_list *list);
void ft_indicexyz(t_list *list, t_input input, t_line *line);
void elevation(t_list *list);
void rotationz(t_list *list);
void zoom(t_list *list);
void translatex(t_list *list);
void translatey(t_list *list);
void ft_bresenham(t_line *line, t_parameter param, t_env *data);
void ft_line_xyprojtop1(t_list *list, t_env *data);
void get_max_z(t_list *list, t_line *line);
int ft_search_top(t_list *ptbegin, t_input input, t_line *entry);
int ft_atoi(const char *str);
int ft_free_list(t_list *lista);
int grad_color(t_line *p, t_parameter param);
void color_to_point(t_list *list);
int key_hook(int keycode, t_list *list);
int mouse_hook();
char **ft_split(char const *s, char c);
char **ft_input_str_space(char *entry);
#endif