/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:41:55 by bpoyet            #+#    #+#             */
/*   Updated: 2024/01/10 16:24:23 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF
#define FDF

#include "minilibx-linux/mlx.h"
#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

#endif