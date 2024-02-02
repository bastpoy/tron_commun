/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:41:55 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/02 17:17:08 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF
#define FDF
#define PI 3.1416
#define TETA PI / 6
#define WHITECOLOR 0xffffff

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
} t_env;

typedef struct s_parameter
{
    int dx;
    int dy;
    int x;
    int y;
    int d;
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
    float z1;
    float x1proj;
    float y1proj;
    int color;
    int index;
    struct s_line *top;
    struct s_line *behind;
    struct s_line *next;
} t_line;

typedef struct s_list
{
    t_line *ptrbegin;
    t_env *data;
    t_input input;
} t_list;

t_list *ft_init_pointbegin();
t_list *ft_fill_struct(t_list *line, t_input input, char *entry);
t_input ft_get_length_width(char *entry);
t_line *ft_input_str_coma(char *str, t_line *line);
t_line *ft_init_tline();
size_t ft_strlen_space_backn(const char *str);
void ft_free_entrystr(char **str);
void ft_read_tline(t_list *list);
void ft_indicexyz(t_list *list, t_line *line, t_input input, int j);
void elevation(t_list *list, t_env *data);
void rotationz(t_list *list, t_env *data);
void zoom(t_list *list, t_env *data);
int ft_search_top(t_list *ptbegin, t_input input, t_line *entry);
int ft_search_behind(t_list *list, t_input input, t_line *entry);
int ft_atoi(const char *str);
int ft_free_list(t_list *lista);
char **ft_split(char const *s, char c);
char **ft_input_str_space(char *entry);
#endif