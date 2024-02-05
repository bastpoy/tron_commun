/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:48:38 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/05 18:53:52 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	*fill_array(t_list *list, t_line *line, t_parameter param)
{
	int	*s;

	s = malloc(sizeof(int) * 2);
	if (!s)
	{
		list->err = 0;
		return (0);
	}
	if (param.x < line->x1proj)
		s[0] = 1;
	else
		s[0] = -1;
	if (param.y < line->y1proj)
		s[1] = 1;
	else
		s[1] = -1;
	return (s);
}

static void	ft_bresenham(t_list * list, t_line *line, t_parameter param, t_env *data)
{
	int	*s;
	int	err;
	int	e2;

	s = fill_array(list, line, param);
	err = param.dx - param.dy;
	while (((int)roundf(line->x1proj) != param.x
		|| (int)roundf(line->y1proj) != param.y) && s)
	{
		mlx_pixel_put(data->mlx_ptr, data->mlx_win, param.x, param.y,
			grad_color(line, param));
		e2 = 2 * err;
		if (e2 > -param.dy)
		{
			err -= param.dy;
			param.x += s[0];
		}
		if (e2 < param.dx)
		{
			err += param.dx;
			param.y += s[1];
		}
	}
	mlx_pixel_put(data->mlx_ptr, data->mlx_win, param.x, param.y, line->color);
	free(s);
}

static t_parameter	fill_param_top(t_line *point, t_parameter param)
{
	param.dx = fabs(roundf(point->x1proj) - roundf(point->top->x1proj));
	param.dy = fabs(roundf(point->y1proj) - roundf(point->top->y1proj));
	param.x = roundf(point->top->x1proj);
	param.y = roundf(point->top->y1proj);
	param.x0 = param.x;
	param.y0 = param.y;
	param.z = point->top->z1;
	param.color = point->top->color;
	return (param);
}

static t_parameter	fill_param_next(t_line *point, t_parameter param)
{
	param.dx = fabs(roundf(point->x1proj) - roundf(point->next->x1proj));
	param.dy = fabs(roundf(point->y1proj) - roundf(point->next->y1proj));
	param.x = roundf(point->next->x1proj);
	param.y = roundf(point->next->y1proj);
	param.x0 = param.x;
	param.y0 = param.y;
	param.z = point->next->z1;
	param.color = point->next->color;
	return (param);
}

void	ft_line_xyprojtop1(t_list *list, t_env *data)
{
	t_line		*point;
	t_parameter	param;

	point = list->ptrbegin;
	while (point  && list->err)
	{
		if (point->top)
		{
			param = fill_param_top(point, param);
			ft_bresenham(list, point, param, data);
		}
		if (point->index % list->input.abs != 0 && point->next)
		{
			param = fill_param_next(point, param);
			ft_bresenham(list, point, param, data);
		}
		point = point->next;
	}
}
