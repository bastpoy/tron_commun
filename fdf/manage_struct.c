/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:42:10 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/04 22:54:43 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_free_list(t_list *lista)
{
    t_line *stacka;
    t_line *tmp;

    stacka = lista->ptrbegin;
    if (!lista)
        return (0);
    while (stacka != NULL)
    {
        tmp = stacka;
        stacka = stacka->next;
        free(tmp);
    }
    free(lista);
    return (1);
}

void ft_read_tline(t_list *list)
{
    t_line *line;

    line = list->ptrbegin;
    while (line)
    {
        if (line->next)
            printf("index %d x %f nextx %f\n", line->index, line->x1, line->next->x1);
        line = line->next;
    }
}

int ft_search_top(t_list *list, t_input input, t_line *entry)
{
    t_line *line;

    line = list->ptrbegin;
    while (line != NULL)
    {
        if (line->index == entry->index - input.abs)
        {
            entry->top = line;
            return (1);
        }
        line = line->next;
    }
    entry->top = NULL;
    return (0);
}

void get_max_z(t_list *list, t_line *line)
{
    if (line->z1 > list->zmax)
        list->zmax = line->z1;
}

void autofocus(t_list *list, t_line *point)
{
    float height;
    float zoom;
    int tr[2];

    tr[0] = list->data->offsetx;
    tr[1] = list->data->offsety;
    if (point->index == 1)
    {
        height = list->data->height;
        zoom = list->data->zoom;
        while (point->x1proj > 300 && point->y1proj > 200)
        {
            point->x1proj = tr[0] + (point->x1 - 0.5 * height * point->z1 * sqrt(3) / 2) * zoom;
            point->y1proj = tr[1] + (point->y1 - 0.5 * height * point->z1 * sqrt(3) / 2) * zoom;
            zoom /= 0.99;
        }
        if (zoom != list->data->zoom)
            zoom *= 0.99;
        list->data->zoom = zoom;
    }
}

void ft_indicexyz(t_list *list, t_input input, t_line *point)
{
    int gapx;
    int gapy;
    float zoom;
    float height;
    float x1origin;
    float y1origin;
    int tr[2];

    tr[0] = list->data->offsetx;
    tr[1] = list->data->offsety;
    zoom = list->data->zoom;
    height = list->data->height;
    // je donne un indice x et y en partan de l'origine (0,0,0)
    if (point->index % input.abs != 0)
        x1origin = (point->index % input.abs) - 1;
    else
        x1origin = input.abs - 1;
    y1origin = (point->index - 1) / input.abs;

    // point->indexe centre tous mes points autour de l'origine (0,0,0)
    gapx = input.abs / 2;
    gapy = input.ord / 2;

    x1origin = x1origin - gapx;
    y1origin = y1origin - gapy;

    point->x1 = x1origin * cos(TETA) - y1origin * sin(TETA);
    point->y1 = x1origin * sin(TETA) + y1origin * cos(TETA);

    x1origin = x1origin + gapx;
    y1origin = y1origin + gapy;

    point->x1proj = tr[0] + (point->x1 - 0.5 * height * point->z1 * sqrt(3) / 2) * zoom;
    point->y1proj = tr[1] + (point->y1 - 0.5 * height * point->z1 * sqrt(3) / 2) * zoom;
    autofocus(list, point);
}
