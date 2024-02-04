#include "fdf.h"

void ft_bresenham(t_line *line, t_parameter param, t_env *data)
{
    int sx;
    int sy;
    int err;
    int e2;

    sx = param.x < line->x1proj ? 1 : -1;
    sy = param.y < line->y1proj ? 1 : -1;
    err = param.dx - param.dy;
    while ((int)roundf(line->x1proj) != param.x || (int)roundf(line->y1proj) != param.y)
    {
        mlx_pixel_put(data->mlx_ptr, data->mlx_win, param.x, param.y, grad_color(line, param));
        e2 = 2 * err;
        if (e2 > -param.dy)
        {
            err -= param.dy;
            param.x += sx;
        }
        if (e2 < param.dx)
        {
            err += param.dx;
            param.y += sy;
        }
    }
    mlx_pixel_put(data->mlx_ptr, data->mlx_win, param.x, param.y, line->color);
}

void ft_line_xyprojtop1(t_list *list, t_env *data)
{
    t_line *point;
    t_parameter param;

    point = list->ptrbegin;
    while (point)
    {
        if (point->top)
        {
            param.dx = fabs(roundf(point->x1proj) - roundf(point->top->x1proj));
            param.dy = fabs(roundf(point->y1proj) - roundf(point->top->y1proj));
            param.x = roundf(point->top->x1proj);
            param.y = roundf(point->top->y1proj);
            param.x0 = param.x;
            param.y0 = param.y;
            param.z = point->top->z1;
            param.color = point->top->color;
            ft_bresenham(point, param, data);
        }
        if (point->index % list->input.abs != 0 && point->next)
        {
            param.dx = fabs(roundf(point->x1proj) - roundf(point->next->x1proj));
            param.dy = fabs(roundf(point->y1proj) - roundf(point->next->y1proj));
            param.x = roundf(point->next->x1proj);
            param.y = roundf(point->next->y1proj);
            param.x0 = param.x;
            param.y0 = param.y;
            param.z = point->next->z1;
            param.color = point->next->color;
            ft_bresenham(point, param, data);
        }
        point = point->next;
    }
}
