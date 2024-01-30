/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:42:10 by bpoyet            #+#    #+#             */
/*   Updated: 2024/01/30 19:48:39 by bpoyet           ###   ########.fr       */
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

    //je fais -1 car sinon j'arrive pas au bout et je rate le derniere element
    lengthx = sqrt(pow(XRIGHTTOP - XLEFTTOP, 2) + pow(YRIGHTTOP - YLEFTTOP, 2)) / (input.abs - 1);
    lengthy = sqrt(pow(XLEFTBOT - XLEFTTOP, 2) + pow(YLEFTBOT - YLEFTTOP, 2)) / (input.ord - 1);
    if (j == 1) // je remplis ma premiere valeur
    {
        line->x1 = XLEFTTOP;
        line->y1 = YLEFTTOP;
        ft_x1y1proj(line);
    }
    else if (j != 1 && j <= input.abs) // je remplis ma premiere ligne
    {
        line->x1 = line->behind->x1 + lengthx / (sqrt(1 + pow(COEFX, 2)));
        line->y1 = line->behind->y1 + (lengthx * COEFX) / sqrt(1 + pow(COEFX, 2));
        ft_x1y1proj(line);
    }
    else if (!line->behind && line->top) // je remplis ma colonne je sais pas pourquoi c'est un -
    {
        line->x1 = line->top->x1 - lengthy / (sqrt(1 + pow(COEFY, 2)));
        line->y1 = line->top->y1 - (lengthy * COEFY) / (sqrt(1 + pow(COEFY, 2)));
        ft_x1y1proj(line);
    }
    else
    {
        line->x1 = line->top->x1 - lengthy / (sqrt(1 + pow(COEFY, 2)));
        line->y1 = line->top->y1 - (lengthy * COEFY) / (sqrt(1 + pow(COEFY, 2)));
        ft_x1y1proj(line);
    }
}

void ft_x1y1proj(t_line *line)
{
    // else
    // {
    // }
    // if(line->z1 == 0)
    // {
    //     line->x1proj = line->x1;
    //     line->y1proj = line->y1;
    //     // line->z1 = 1;
    // }
    // else
    // {
        line->x1proj = (sqrt(2) / 2) * (line->x1 - line->y1)+ 200;
        line->y1proj = (sqrt(2)/sqrt(3) * (-5 * line->z1)) - (1 / sqrt(6)) * (line->x1 + line->y1) + 800;
        // printf("%f\n",line->y1proj);
    // }
}