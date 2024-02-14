/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:08:47 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/14 17:40:54 by bpoyet           ###   ########.fr       */
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
int ft_count_rra(t_listx *lista, t_listx *listb)
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

int ft_count_rrb(t_listx *listb, t_listx *lista)
{
    t_stack *stackb;
    t_stack *stacka;
    int count;

    stackb = listb->ptrbegin;
    stacka = lista->ptrbegin;
    count = 1;
    // je compare stack a avec la liste b
    while (stacka && stacka->next)
    {
        if (stackb->number > stacka->number &&
            stackb->number < stacka->next->number)
        {
            return (count);
        }
        count++;
        stacka = stacka->next;
    }
    return (1);
}

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
        i++;
        ft_pb(lista, listb);
        while (i != 0)
        {
            ft_rb(listb);
            i--;
        }
    }
}

void ft_rrb_or_rb1(int count, t_listx *listb, t_listx *lista)
{
    int i;
    int sizea;

    i = 0;
    sizea = ft_size_listx(lista);
    if (count <= (sizea) / 2)
    {
        while (i != count)
        {
            ft_ra(lista);
            i++;
        }
        ft_pa(lista, listb);
        while (i != 0)
        {
            ft_rra(lista);
            i--;
        }
    }
    else
    {
        while (i != (sizea)-count)
        {
            ft_rra(lista);
            i++;
        }
        i++;
        ft_pa(lista, listb);
        while (i != 0)
        {
            ft_ra(lista);
            i--;
        }
    }
}

int ft_put_minmax_stack(t_listx *lista, t_listx *listb)
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
    {
        return (0);
    }
}

int ft_put_minmax_stack1(t_listx *listb, t_listx *lista)
{
    t_stack *stackb;
    t_stack *stacka;
    t_stack *temp;

    stackb = listb->ptrbegin;
    stacka = lista->ptrbegin;
    temp = ft_get_last(lista);
    if (stackb->number < stacka->number)
    {
        ft_pa(lista, listb);
        return (1);
    }
    else if (stackb->number > temp->number)
    {
        ft_pa(lista, listb);
        ft_ra(lista);
        return (1);
    }
    else
    {
        return (0);
    }
}
