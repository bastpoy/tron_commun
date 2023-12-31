/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:08:47 by bpoyet            #+#    #+#             */
/*   Updated: 2023/12/20 15:38:38 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// premiere insertition dans b
void ft_first_insert_listb(t_listx *lista, t_listx *listb)
{
    t_stack *stackb;

    stackb = listb->ptrbegin;
    if (!stackb)
    {
        ft_pb(lista, listb);
    }
}

// deuxieme insertion dans b
void ft_second_insert_listb(t_listx *lista, t_listx *listb)
{
    t_stack *stackb;

    stackb = listb->ptrbegin;
    if (!stackb->next)
    {
        ft_pb(lista, listb);
        stackb = listb->ptrbegin;
        if (stackb->number < stackb->next->number)
            ft_sb(listb);
    }
}

// hypothese que le nombre que je renvoie est en haut de la pile
int ft_count_rrb(t_listx *lista, t_listx *listb)
{
    t_stack *stacka;
    t_stack *stackb;
    int count;

    stacka = lista->ptrbegin;
    stackb = listb->ptrbegin;
    count = 1;
    // je compare stack a avec la liste b
    while (stackb && stackb->next)
    {
        if (stacka->number < stackb->number &&
            stacka->number > stackb->next->number)
        {
            return (count);
        }
        count++;
        stackb = stackb->next;
    }
    return (1);
}

// je calcule combien de fois je dois faire de rrb pour arriver caller mon nombre
// Suivant le nombre de fois je fais rrb ou rb
// Je calle mon nombre
// Je refais le meme nombre de rb ou rrb pour recaller ma pile
void ft_rrb_or_rb(int count, t_listx *lista, t_listx *listb)
{
    int i;
    int sizeb;

    i = 0;
    sizeb = ft_size_listx(listb);
    // si mon count rrb est superieur a la moitie de mes sizeb
    if (count <= (sizeb) / 2)
    {
        // je decalle de rb du nombre sizeb - 1 - count
        while (i != count)
        {
            ft_rb(listb);
            i++;
        }
        // je passe l'indice dedans
        ft_pb(lista, listb);
        // je me recalle du nombre de rb
        while (i != 0)
        {
            ft_rrb(listb);
            i--;
        }
    }
    else
    {
        while (i != (sizeb)-count)
        {
            ft_rrb(listb);
            i++;
        }
        ft_pb(lista, listb);
        while (i != 0)
        {
            ft_rb(listb);
            i--;
        }
    }
}

// fonction qui prend le max de b et le compare avec a
// le met dans la stack si a > maxb
// fonction qui prend le min de b et le compare avec a
// le met dans la stack si a < minb
int ft_put_minmax_stacka(t_listx *lista, t_listx *listb)
{
    t_stack *stacka;
    t_stack *stackb;
    t_stack *temp;

    stacka = lista->ptrbegin;
    stackb = listb->ptrbegin;
    temp = ft_get_last(listb);
    if (stacka->number > stackb->number)
    {
        ft_pb(lista, listb);
        return (1);
    }
    else if (stacka->number < temp->number)
    {
        ft_pb(lista, listb);
        ft_rb(listb);
        return (1);
    }
    else
        return (0);
}
