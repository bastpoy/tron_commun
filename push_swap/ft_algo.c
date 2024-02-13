/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 16:04:47 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/13 17:41:50 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int ft_entry_two(t_listx lista, char *str)
// {
//     char **tab;
//     int i = 0;

//     tab = ft_split(str, ' ');
//     while (tab[i])
//     {
//         if (!atoi(tab[i]))
//             return (0);
//         i++;
//     }
//     return (1);
// }

int ft_entry_three(t_listx *lista)
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
    return (0);
}

int ft_entry_five(t_listx *lista, t_listx *listb)
{
    int count;

    ft_pb(lista, listb);
    ft_pb(lista, listb);
    ft_sort_threenbr(lista);

    if (!ft_put_minmax_stack1(listb, lista))
    {
        count = ft_count_rrb(listb, lista);
        ft_rrb_or_rb1(count, listb, lista);
    }
    if (!ft_put_minmax_stack1(listb, lista))
    {
        count = ft_count_rrb(listb, lista);
        ft_rrb_or_rb1(count, listb, lista);
    }
    ft_free_lista(lista);
    ft_free_listb(listb);
    return (0);
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
