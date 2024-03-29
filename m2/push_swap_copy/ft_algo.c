/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 16:04:47 by bpoyet            #+#    #+#             */
/*   Updated: 2024/01/29 23:10:53 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_entry_three(t_listx *lista)
{
    t_stack *stacka = lista->ptrbegin;
    t_stack *stackanext = stacka->next;

    if (stacka->number > stackanext->number &&
        stackanext->number > stackanext->next->number)
    {
        ft_sa(lista);
        ft_rra(lista);
    }
    else if (stackanext->number > stackanext->next->number &&
             stackanext->next->number > stacka->number)
    {
        ft_sa(lista);
        ft_ra(lista);
    }
    else if (stacka->number > stackanext->next->number &&
             stackanext->next->number > stackanext->number)
        ft_ra(lista);
    else if (stackanext->next->number > stacka->number &&
             stacka->number > stackanext->number)
        ft_sa(lista);
    else if (stackanext->number > stacka->number &&
             stacka->number > stackanext->next->number)
        ft_rra(lista);
}

// Je cree un algo qui trie si l'entree fait 5 nombres.
// je passe deux nombre dans b
// je trie les trois nombres de a
// je repasse les deux nombre de b dans a en optimisant rra et ra
void ft_entry_five(t_listx *lista, t_listx *listb)
{
    int count;

    ft_pb(lista, listb);
    ft_pb(lista, listb);
    ft_sort_threenbr(lista);
    ft_print_listx(lista);
    ft_print_listx(listb);
    while (listb->ptrbegin)
    {
        if (!ft_put_minmax_stack1(listb, lista))
        {
            count = ft_count_rrb1(listb, lista);
            ft_rrb_or_rb1(count, lista, listb);
        }
        ft_print_listx(lista);
    }
}

int ft_check_if_sort(t_listx *lista)
{
    t_stack *stacka;

    stacka = lista->ptrbegin;
    while (stacka != NULL)
    {
        if (stacka->next)
        {
            if (stacka->number > stacka->next->number)
                return (0);
        }
        stacka = stacka->next;
    }
    return (1);
}

// void ft_entry_supfive(t_listx *lista, t_listx *listb)
// {
//     // diviser les nombres selon la quantite
//     // je divise par 5 a chaque fois
// }