/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:42:10 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/02 01:00:31 by bpoyet           ###   ########.fr       */
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

void ft_indicexyz(t_line *line, t_input input, int j)
{
    // int gapx;
    // int gapy;

    // je donne un indice x et y en partan de l'origine (0,0,0)
    if (j % input.abs != 0)
        line->x1 = (j % input.abs) - 1;
    else
        line->x1 = input.abs - 1;
    line->y1 = (j - 1) / input.abs;

    // je centre tous mes points autour de l'origine (0,0,0)
    // gapx = input.abs / 2;
    // gapy = input.ord / 2;
    // line->x1 = line->x1 - gapx;
    // line->y1 = line->y1 - gapy;

    line->x1 = line->x1 * cos(PI / 10) - line->y1 * sin(PI / 10);
    line->y1 = line->x1 * sin(PI / 10) + line->y1 * cos(PI / 10);

    // line->x1 = line->x1 + gapx;
    // line->y1 = line->y1 + gapy;

    // line->x1proj = line->x1 * 15 + 500;
    // line->y1proj = line->y1 * 20 + 500;

    if (line->z1 == 0)
        line->z1 = 1;
    // line->x1proj = (sqrt(2) / 2) * (line->x1 - line->y1);
    // line->y1proj = (sqrt(2) / sqrt(3) * (line->y1)) - (1 / sqrt(6)) * (line->x1 + line->y1);
    line->x1proj = (50 + line->x1 - 0.5 * line->z1 * sqrt(3) / 2) * 20;
    line->y1proj = (20 + line->y1 - 0.5 * line->z1 * sqrt(3) / 2) * 20;
    // line->x1proj = (((1.03 * line->x1 / line->z1) + 1)) * 100 / 2 + 300;
    // line->y1proj = (((1.83 * line->y1 / line->z1) + 1)) * 50 / 2;

    // printf("x %f y %f z %f et index %d \n", line->x1, line->y1, line->z1, line->index);
}

void change_height(t_list *list, t_env *data)
{
    t_line *point;

    point = list->ptrbegin;
    while (point)
    {
        point->x1proj = (50 + point->x1 - 0.5 * data->height * point->z1 * sqrt(3) / 2) * 20;
        point->y1proj = (20 + point->y1 - 0.5 * data->height * point->z1 * sqrt(3) / 2) * 20;
        point = point->next;
    }
}