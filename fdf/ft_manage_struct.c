/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:42:10 by bpoyet            #+#    #+#             */
/*   Updated: 2024/01/31 19:34:34 by bpoyet           ###   ########.fr       */
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
    float deltaxhori;
    float deltayhori;
    float deltaxverti;
    float deltayverti;

    // printf("horiangle %f\n", HORIANGLE);
    // je fais -1 car sinon j'arrive pas au bout et je rate le derniere element
    lengthx = sqrt(pow(XRIGHTTOP - XLEFTTOP, 2) + pow(YRIGHTTOP - YLEFTTOP, 2)) / (input.abs - 1);
    lengthy = sqrt(pow(XLEFTBOT - XLEFTTOP, 2) + pow(YLEFTBOT - YLEFTTOP, 2)) / (input.ord - 1);
    deltaxhori = lengthx * cos(HORIANGLE);
    deltayhori = lengthy * sin(HORIANGLE);
    deltaxverti = lengthx * cos(VERTANGLE);
    deltayverti = lengthy * sin(VERTANGLE);

    // printf("%f et %f \n", lengthx, lengthy);
    if (j == 1) // je remplis ma premiere valeur
    {
        line->x1 = XLEFTTOP;
        line->y1 = YLEFTTOP;
        ft_x1y1proj(line);
    }
    else if(j != 1 && j <= input.abs)
    {
        line->x1 = line->behind->x1 + deltaxverti;
        line->y1 = line->behind->y1 + deltayverti;
        ft_x1y1proj(line);
    }
    else
    {
        line->x1 = line->top->x1 + deltaxhori;
        line->y1 = line->top->y1 + deltayhori;
        ft_x1y1proj(line);   
    }
    // else if (j != 1 && j <= input.abs) // je remplis ma premiere ligne
    // {
    //     if(COEFY != 0)
    //     {
    //         line->x1 = line->behind->x1 + lengthx / (sqrt(1 + pow(COEFX, 2)));
    //         line->y1 = line->behind->y1 + (lengthx * COEFX) / sqrt(1 + pow(COEFX, 2));
    //     }
    //     else
    //     {
                
    //         line->y1 = line->behind->y1 + lengthx;
    //     }
    //     ft_x1y1proj(line);
    //     printf("x1 %f y1 %f et index %d\n", line->x1proj, line->y1proj, line->index);
    // }
    // else // je remplis le reste
    // {
    //     line->x1 = line->top->x1 - lengthy / (sqrt(1 + pow(COEFY, 2)));
    //     if(COEFY != 0)
    //         line->y1 = line->top->y1 - (lengthy * COEFY) / (sqrt(1 + pow(COEFY, 2)));
    //     else
    //         line->y1 = line->top->y1 + lengthx;
    //     ft_x1y1proj(line);
    // }

}

void ft_x1y1proj(t_line *line)
{

    if(line->z1 == 0)
        line->z1 = 1;
    // {
    line->x1proj = line->x1;
    line->y1proj = line->y1;
    // }
    // else
    // {
    // line->x1proj = (sqrt(2) / 2) * (line->x1 + 2 * line->z1);
    // line->y1proj = -(sqrt(2) / sqrt(3) * (line->y1)) + (1 / sqrt(6)) * (line->x1 + line->z1) + 500;
    // line->x1proj = line->x1 - line->z1 * sqrt(3)/2 + 100;
    // line->y1proj = line->y1 - line->z1 * sqrt(3)/2 + 200;

    // line->x1proj = line->x1 * cos(0.75) - line->y1 * sin(0.75);
    // line->y1proj = line->x1 * cos(0.75) + line->y1 * sin(0.75) - line->z1 -300;

    //rotation x
    // line->y1proj = line->y1proj * cos(0.5236) - line->z1 * sin(0.5236);
    
    // rotation y
    // line->x1proj = line->x1proj * cos(1.1) + line->z1 * sin (1.1);
    
    // rotation le long de l'origine autour de x
    // line->x1 = line->x1proj * cos(PI/6) - line->y1proj * sin(PI/6) ;
    // line->y1proj = line->x1proj * sin(PI/6) + line->y1proj * cos(PI/6) ;
    
    //test avec la video
    // line->x1proj = ((2.1 * line->x1 / (10 *line->y1)) + 1) / 2 * 1920;
    // line->y1proj = ((2 * line->z1 / line->y1) + 1) / 2 * 1080 ;
}