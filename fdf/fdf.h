/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:41:55 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/02 01:03:05 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF
#define FDF
#define COEFX 0
#define COEFY 0
#define PI 3.1416
#define HORIANGLE PI / 2
#define VERTANGLE 0
#define XLEFTTOP 0
#define YLEFTTOP 0
#define XRIGHTTOP 426
#define YRIGHTTOP 0
#define XLEFTBOT 0
#define YLEFTBOT 243
#define LONGUEUR sqrt(pow(XRIGHTTOP - XLEFTTOP, 2) + pow(YRIGHTTOP - YLEFTTOP, 2))
#define LONGUEUR2 sqrt(pow(XLEFTBOT - XLEFTTOP, 2) + pow(YLEFTBOT - YLEFTTOP, 2))
#define ANGLE 0.5236
#define WHITECOLOR 0xffffff

#include "minilibx-linux/mlx.h"
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
} t_list;

t_list *ft_init_pointbegin();
t_list *ft_fill_struct(t_list *line, t_input input);
t_input ft_get_length_width();
t_line *ft_input_str_coma(char *str, t_line *line);
t_line *ft_init_tline();
void ft_x1y1proj(t_line *line);
size_t ft_strlen_space_backn(const char *str);
void ft_free_entrystr(char **str);
void ft_read_tline(t_list *list);
void ft_search_x1y1(t_list *list, t_input input);
void ft_x1y1topbeh(t_line *line, t_input input, int j);
void ft_indicexyz(t_line *line, t_input input, int j);
void change_height(t_list *list, t_env *data);
int ft_search_top(t_list *ptbegin, t_input input, t_line *entry);
int ft_search_behind(t_list *list, t_input input, t_line *entry);
int **ft_fill_entry_num(t_input input);
int ft_atoi(const char *str);
int ft_free_list(t_list *lista);
char **ft_split(char const *s, char c);
char **ft_input_str_space();
#endif