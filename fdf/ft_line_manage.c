/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_manage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 00:28:37 by bpoyet            #+#    #+#             */
/*   Updated: 2024/01/11 02:07:21 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_line ft_create_tline(double xa, double xb, double ya, double yb)
{
    t_line point;
    point.xa = xa;
    point.xb = xb;
    point.ya = ya;
    point.yb = yb;

    return (point);
}

double ft_line_length(t_line line)
{
    int length;

    length = sqrt(pow(line.xb - line.xa, 2) + pow(line.yb - line.ya, 2));
    return (length);
}

t_line ft_create_line(t_line line, double length, t_line line2, double length2)
{
    double xa;
    double ya;
    double xb;
    double yb;
    double coef;
    double yzero;
    t_line finalline;

    coef = (line.yb - line.ya) / (line.xb - line.xa);
    yzero = line.ya - (coef * line.xa);
    xa = line.xa + (length / sqrt(1 + pow(coef, 2)));
    ya = coef * xa + yzero;
    printf("coef %f length %f coef %f et yzero %f xa %f et ya %f\n", pow(coef, 2), length, coef, yzero, xa, ya);

    coef = (line2.yb - line2.ya) / (line2.xb - line2.xa);
    yzero = line2.ya - (coef * line2.xa);
    xb = line2.xa + (length2 / sqrt(1 + pow(coef, 2)));
    yb = coef * xb + yzero;

    printf("coef %f et yzero %f xb %f et yb %f\n", coef, yzero, xb, yb);

    finalline = ft_create_tline(xa, xb, ya, yb);
    return (finalline);
}
