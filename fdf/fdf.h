/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:41:55 by bpoyet            #+#    #+#             */
/*   Updated: 2024/01/26 14:11:13 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF
#define FDF
#define COEFX 0.625
#define COEFY -0.875
#define XLEFTTOP 800
#define YLEFTTOP 100
#define XRIGHTTOP 1600
#define YRIGHTTOP 600
#define XLEFTBOT 380
#define YLEFTBOT 467.5
#define LONGUEUR sqrt(pow(XRIGHTTOP - XLEFTTOP, 2) + pow(YRIGHTTOP - YLEFTTOP, 2))
#define LONGUEUR2 sqrt(pow(XLEFTBOT - XLEFTTOP, 2) + pow(YLEFTBOT - YLEFTTOP, 2))
#define WHITECOLOR 0xffffff

#include "minilibx-linux/mlx.h"
#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <limits.h>

typedef struct s_data
{
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
} t_data;

typedef struct s_extremities
{
    int xa;
    int xb;
    int ya;
    int yb;
} t_extremities;

typedef struct s_parameter
{
    float dx;
    float dy;
    int x;
    int y;
    int d;
    float coef;
} t_parameter;

typedef struct s_input
{
    float abs;
    float ord;
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
} t_list;

t_extremities ft_create_tline(double xa, double xb, double ya, double yb);
t_extremities ft_create_line(t_extremities line, double length, t_extremities line2, double length2);
t_list *ft_init_pointbegin();
t_list *ft_fill_struct(t_list *line, t_input input, int fd);
t_input ft_get_length_width();
t_line *ft_input_str_coma(char *str, t_line *line);
t_line *ft_init_tline();
t_line *ft_x1y1proj(t_line *line);
size_t ft_strlen_space_backn(const char *str);
double ft_line_length(t_extremities line);
void ft_line(void *mlx_ptr, void *mlx_win, t_data img, t_extremities point);
void ft_free_entrystr(char **str);
void ft_read_tline(t_list *list);
void ft_search_x1y1(t_list *list, t_input input);
void ft_x1y1topbeh(t_line *line, t_input input, int j);
int ft_search_top(t_list *ptbegin, t_input input, t_line *entry);
int ft_search_behind(t_list *list, t_input input, t_line *entry);
int **ft_fill_entry_num(t_input input);
int ft_atoi(const char *str);
int ft_free_list(t_list *lista);
char **ft_split(char const *s, char c);
char **ft_input_str_space();
#endif