#include "fdf.h"

int get_dst(int start, int end, int current)
{
    int place;
    int distance;

    place = current - start;
    distance = end - start;
    if (distance == 0)
        return (1);
    else
        return (place / distance);
}

int get_pos_gradient(int start, int end, float pos)
{
    return ((int)((1 - pos) * start + pos * end));
}

int interpolate_color(int min_color, int max_color, double percentage)
{
    int red;
    int green;
    int blue;

    red = get_pos_gradient((min_color >> 16) & 0xFF, (max_color >> 16) & 0xFF, percentage);
    green = get_pos_gradient((min_color >> 8) & 0xFF, (max_color >> 8) & 0xFF, percentage);
    blue = get_pos_gradient(min_color & 0xFF, max_color & 0xFF, percentage);
    return (red << 16) | (green << 8) | blue;
}

void color_to_point(t_list *list)
{
    t_line *point;
    float percentage;

    point = list->ptrbegin;
    while (point)
    {
        if (point->z1 != 0)
        {
            percentage = (float)point->z1 / (float)list->zmax;
            point->color = interpolate_color(MINCOLOR, MAXCOLOR, percentage);
            printf("color %d et index %d et z %d et perc %f\n", point->color, point->index, point->z1, percentage);
        }
        point = point->next;
    }
}

int grad_color(t_line *p, t_parameter param)
{
    float pos;
    int red;
    int green;
    int blue;

    if (param.z == p->z1)
        return (p->color);
    if (param.dx > param.dy)
        pos = get_dst(param.x0, p->x1proj, param.x);
    else
        pos = get_dst(param.y0, p->y1proj, param.y);
    red = get_pos_gradient((p->color >> 16) & 0xFF, (param.color >> 16) & 0xFF, pos);
    green = get_pos_gradient((p->color >> 8) & 0xFF, (param.color >> 8) & 0xFF, pos);
    blue = get_pos_gradient(p->color & 0xFF, param.color & 0xFF, pos);
    return ((red << 16) | (green << 8) | blue);
}