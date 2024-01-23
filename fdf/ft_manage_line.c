/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 00:28:37 by bpoyet            #+#    #+#             */
/*   Updated: 2024/01/19 16:09:00 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double ft_line_length(t_extremities line)
{
    double length;

    length = sqrt(pow(line.xb - line.xa, 2) + pow(line.yb - line.ya, 2));
    return (length);
}

t_extremities ft_create_tline(double xa, double xb, double ya, double yb)
{
    t_extremities point;
    point.xa = xa;
    point.xb = xb;
    point.ya = ya;
    point.yb = yb;

    return (point);
}

t_extremities ft_create_line(t_extremities line, double length, t_extremities line2, double length2)
{
    double xa;
    double ya;
    double xb;
    double yb;
    double coef;
    double yzero;
    t_extremities finalline;

    coef = (line.yb - line.ya) / (line.xb - line.xa);
    yzero = line.ya - (coef * line.xa);
    if (coef < 0)
        xa = line.xa - (length / sqrt(1 + pow(coef, 2)));
    else
        xa = line.xa + (length / sqrt(1 + pow(coef, 2)));
    ya = coef * xa + yzero;
    printf("coef %f length %f coef %f et yzero %f xa %f et ya %f\n", pow(coef, 2), length, coef, yzero, xa, ya);

    coef = (line2.yb - line2.ya) / (line2.xb - line2.xa);
    yzero = ya - (coef * xa);
    if (coef < 0)
        xb = xa - (length2 / sqrt(1 + pow(coef, 2)));
    else
        xb = xa + (length2 / sqrt(1 + pow(coef, 2)));
    yb = coef * xb + yzero;

    printf("coef %f et yzero %f xb %f et yb %f\n", coef, yzero, xb, yb);

    finalline = ft_create_tline(xa, xb, ya, yb);
    return (finalline);
}
