/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:42:10 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/02 16:50:24 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list *ft_init_pointbegin()
{
    t_list *list;

    list = malloc(sizeof(t_list));
    list->ptrbegin = NULL;
    list->data = NULL;
    return (list);
}

t_line *ft_init_tline()
{
    t_line *line;

    line = malloc(sizeof(t_line));
    line->x1 = 0;
    line->y1 = 0;
    line->x1proj = 0;
    line->y1proj = 0;
    line->z1 = 0;
    line->color = 0;
    line->index = -1;
    line->next = NULL;
    line->top = NULL;
    line->behind = NULL;
    return (line);
}

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

// cette fonction me permet de prendre l'index du dessus pour pouvoir tracer la droite du haut
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

int ft_search_behind(t_list *list, t_input input, t_line *entry)
{
    t_line *line;

    (void)input;
    line = list->ptrbegin;
    while (line != NULL)
    {
        if (line->index == entry->index - 1 &&
            ((entry->index - 1) % ((int)input.abs) != 0))
        {
            entry->behind = line;
            return (1);
        }
        line = line->next;
    }
    return (0);
}

void ft_indicexyz(t_list *list, t_line *point, t_input input, int j)
{
    int gapx;
    int gapy;
    int zoom;
    float x1origin;
    float y1origin; 

    zoom = list->data->zoom;
    // je donne un indice x et y en partan de l'origine (0,0,0)
    if (j % input.abs != 0)
        x1origin= (j % input.abs) - 1;
    else
        x1origin= input.abs - 1;
    y1origin = (j - 1) / input.abs;

    // je centre tous mes points autour de l'origine (0,0,0)
    gapx = input.abs / 2;
    gapy = input.ord / 2;

    x1origin= x1origin- gapx;
    y1origin = y1origin - gapy;

    point->x1 = x1origin* cos(TETA) - y1origin * sin(TETA);
    point->y1 = x1origin* sin(TETA) + y1origin * cos(TETA);
    
    x1origin= x1origin+ gapx;
    y1origin = y1origin + gapy;
    point->x1proj = 1000 + (point->x1 - 0.5 * point->z1 * sqrt(3) / 2) * zoom;
    point->y1proj = 500 + (point->y1 - 0.5 * point->z1 * sqrt(3) / 2) * zoom;
    // printf("indice %d\n", point->index);
}

void elevation(t_list *list, t_env *data)
{
    t_line *point;
    float zoom;
    float height;

    zoom = data->zoom;
    height = data->height;
    point = list->ptrbegin;
    while (point)
    {
        point->x1proj = 1000 + (point->x1 - 0.5 * height * point->z1 * sqrt(3) / 2) * zoom;
        point->y1proj = 500 + (point->y1 - 0.5 * height * point->z1 * sqrt(3) / 2) * zoom;
        point = point->next;
    }
}

void rotationz(t_list *list, t_env *data)
{
    t_line *point;
    float zoom;
    float height;

    zoom = data->zoom;
    height = data->height;
    point = list->ptrbegin;
    while(point)
    {
        float q[4] = {cos(data->angle / 2), 0, 0, sin(data->angle / 2)};
        float p[4] = {0, point->x1, point->y1, 0};
        float result[4];
        result[0] = p[0]*q[0] - p[1]*q[1] - p[2]*q[2] - p[3]*q[3];
        result[1] = p[0]*q[1] + p[1]*q[0] + p[2]*q[3] - p[3]*q[2];
        result[2] = p[0]*q[2] - p[1]*q[3] + p[2]*q[0] + p[3]*q[1];
        result[3] = p[0]*q[3] + p[1]*q[2] - p[2]*q[1] + p[3]*q[0];
        point->x1 = result[1];
        point->y1 = result[2];
        point->x1proj = 1000 + (point->x1 - 0.5 * height * point->z1 * sqrt(3) / 2) * 20 * zoom;
        point->y1proj = 500 + (point->y1 - 0.5 * height * point->z1 * sqrt(3) / 2) * 20 * zoom;   
        point = point->next;
    }   
}

void zoom(t_list *list, t_env *data)
{
    t_line *point;
    float zoom;
    float height;

    zoom = data->zoom;
    height = data->height;
    point = list->ptrbegin;
    printf("%f\n", zoom);
    while (point)
    {
        point->x1proj = 1000 + (point->x1 - 0.5 * height * point->z1 * sqrt(3) / 2)* zoom;
        point->y1proj = 500 + (point->y1 - 0.5 * height * point->z1 * sqrt(3) / 2)* zoom;
        point = point->next;
    }   
}

// void autofocus(t_list *list, t_line *point)
// {
    
// }