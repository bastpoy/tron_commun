#include "fdf.h"

void elevation(t_list *list)
{
    t_line *point;
    float zoom;
    float height;
    int tr[2];

    tr[0] = list->data->offsetx;
    tr[1] = list->data->offsety;
    zoom = list->data->zoom;
    height = list->data->height;
    point = list->ptrbegin;
    while (point)
    {
        point->x1proj = tr[0] + (point->x1 - 0.5 * height * point->z1 * sqrt(3) / 2) * zoom;
        point->y1proj = tr[1] + (point->y1 - 0.5 * height * point->z1 * sqrt(3) / 2) * zoom;
        point = point->next;
    }
}

void zoom(t_list *list)
{
    t_line *point;
    float zoom;
    float height;
    int tr[2];

    tr[0] = list->data->offsetx;
    tr[1] = list->data->offsety;
    zoom = list->data->zoom;
    height = list->data->height;
    point = list->ptrbegin;
    while (point)
    {
        point->x1proj = tr[0] + (point->x1 - 0.5 * height * point->z1 * sqrt(3) / 2) * zoom;
        point->y1proj = tr[1] + (point->y1 - 0.5 * height * point->z1 * sqrt(3) / 2) * zoom;
        point = point->next;
    }
}

void rotationz(t_list *list)
{
    t_line *point;
    float zoom;
    float height;
    int tr[2];

    tr[0] = list->data->offsetx;
    tr[1] = list->data->offsety;
    zoom = list->data->zoom;
    height = list->data->height;
    point = list->ptrbegin;
    while (point)
    {
        float q[4] = {cos(list->data->angle / 2), 0, 0, sin(list->data->angle / 2)};
        float p[4] = {0, point->x1, point->y1, 0};
        float result[4];
        result[0] = p[0] * q[0] - p[1] * q[1] - p[2] * q[2] - p[3] * q[3];
        result[1] = p[0] * q[1] + p[1] * q[0] + p[2] * q[3] - p[3] * q[2];
        result[2] = p[0] * q[2] - p[1] * q[3] + p[2] * q[0] + p[3] * q[1];
        result[3] = p[0] * q[3] + p[1] * q[2] - p[2] * q[1] + p[3] * q[0];
        point->x1 = result[1];
        point->y1 = result[2];
        point->x1proj = tr[0] + (point->x1 - 0.5 * height * point->z1 * sqrt(3) / 2) * zoom;
        point->y1proj = tr[1] + (point->y1 - 0.5 * height * point->z1 * sqrt(3) / 2) * zoom;
        point = point->next;
    }
}

void translatex(t_list *list)
{
    t_line *point;
    float zoom;
    float height;
    int tr[2];

    tr[0] = list->data->offsetx;
    tr[1] = list->data->offsety;
    zoom = list->data->zoom;
    height = list->data->height;
    point = list->ptrbegin;
    while (point)
    {
        point->x1proj = tr[0] + (point->x1 - 0.5 * height * point->z1 * sqrt(3) / 2) * zoom;
        point->y1proj = tr[1] + (point->y1 - 0.5 * height * point->z1 * sqrt(3) / 2) * zoom;
        point = point->next;
    }
}

void translatey(t_list *list)
{
    t_line *point;
    float zoom;
    float height;
    int tr[2];

    tr[0] = list->data->offsetx;
    tr[1] = list->data->offsety;
    zoom = list->data->zoom;
    height = list->data->height;
    point = list->ptrbegin;
    while (point)
    {
        point->x1proj = tr[0] + (point->x1 - 0.5 * height * point->z1 * sqrt(3) / 2) * zoom;
        point->y1proj = tr[1] + (point->y1 - 0.5 * height * point->z1 * sqrt(3) / 2) * zoom;
        point = point->next;
    }
}
