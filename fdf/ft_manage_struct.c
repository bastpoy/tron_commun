/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:42:10 by bpoyet            #+#    #+#             */
/*   Updated: 2024/01/25 21:00:41 by bpoyet           ###   ########.fr       */
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

void ft_x1y1topbeh(t_line *line, t_input input, int j)
{
    float lengthx;
    float lengthy;

    lengthx = sqrt(pow(XRIGHTTOP - XLEFTTOP, 2) + pow(YRIGHTTOP - YLEFTTOP, 2)) / input.abs;
    lengthy = sqrt(pow(XLEFTBOT - XLEFTTOP, 2) + pow(YLEFTBOT - YLEFTTOP, 2)) / input.ord;
    // printf("lengthx %f lengthy %f \n", lengthx, lengthy);
    if (j == 1) // je remplis ma premiere valeur
    {
        line->x1 = XLEFTTOP;
        line->y1 = YLEFTTOP;
    }
    else if (j != 1 && j <= input.abs) // je remplis ma premiere ligne
    {
        line->x1 = line->behind->x1 + lengthx / (sqrt(1 + pow(COEFX, 2)));
        line->y1 = line->behind->y1 + (lengthx * COEFX) / sqrt(1 + pow(COEFX, 2));
        printf("line x1 %f y1 %f\n", line->x1, line->y1);
    }
    else if (!line->behind && line->top) // je remplis ma colonne
    {
        line->x1 = line->top->x1 + lengthy / (sqrt(1 + pow(COEFY, 2)));
        line->y1 = line->top->y1 + (lengthy * COEFY) / (sqrt(1 + pow(COEFY, 2)));
    }
    else
    {
        if (j < 55)
            printf("%f %f index %d \n", line->top->x1, line->top->x1);
        line->x1 = line->top->x1 - lengthy / (sqrt(1 + pow(COEFY, 2)));
        line->y1 = line->top->y1 - (lengthy * COEFY) / (sqrt(1 + pow(COEFY, 2)));
        // printf("index %d line->x1 %f et line->top->x1 %f\n",line->index, line->y1, line->top->y1);
    }
}

t_line *ft_x1y1proj(t_line *line)
{
    if (line->coeffdir != 0)
    {
        line->x1 = line->x1 / line->coeffdir;
        line->y1 = line->y1 / line->coeffdir;
    }
    return (line);
}