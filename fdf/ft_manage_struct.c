/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:42:10 by bpoyet            #+#    #+#             */
/*   Updated: 2024/01/19 16:44:05 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list *ft_init_pointbegin()
{
    t_list *lista;

    lista = malloc(sizeof(t_list));
    lista->ptrbegin = NULL;
    return (lista);
}

t_line *ft_init_tline()
{
    t_line *line;

    line = malloc(sizeof(t_line));
    line->x1 = 0;
    line->y1 = 0;
    line->coeffdir = 0;
    line->color = 0;
    line->distance = 0;
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

t_line *ft_get_last(t_list *ptbegin)
{
    t_line *line;

    line = ptbegin->ptrbegin;
    while (line)
    {
        if (line->next == NULL)
            return (line);
        else
            line = line->next;
    }
    return (line);
}

void ft_read_tline(t_list *list)
{
    t_line *line;

    line = list->ptrbegin;
    while (line->next != NULL)
    {
        if (line->x1 != 0 && line->behind != NULL)
            printf("index %d x1 %f y1 %f x1 behind %f y1behind %f\n", line->index, line->x1, line->y1, line->behind->x1, line->behind->y1);
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
        if (line->index == entry->index - 1 && (entry->index % (input.abs + 1) != 0))
        {
            entry->behind = line;
            return (1);
        }
        line = line->next;
    }
    return (0);
}

void ft_search_x1y1(t_list *list, t_input input)
{
    t_line *line;
    int j;

    j = 0;
    line = list->ptrbegin;
    while (line)
    {
        if (line->top == NULL && j == 0)
        {
            line->x1 = XLEFTTOP;
            line->y1 = YLEFTTOP;
            printf("dans j == 0 j %d\n", j);
        }
        if (line->top == NULL && j != 0 && j < input.abs)
        {
            printf("j %d\n", j);
            line->x1 = line->behind->x1 + ((LONGUEUR / input.abs) / (sqrt(1 + pow(COEFX, 2))));
            line->y1 = line->behind->y1 + (LONGUEUR / input.abs) * (COEFX / (1 + COEFX));
        }
        j++;
        line = line->next;
    }
}

// t_line *ft_insert_back(t_pointbegin *ptbegin, int nb)
// {
//     t_line *line;

//     line = ft_get_last(ptbegin);
//     line->next = malloc(sizeof(t_line));
//     line->next->next = NULL;
//     return (line->next);
// }