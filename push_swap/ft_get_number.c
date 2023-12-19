/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:08:47 by bpoyet            #+#    #+#             */
/*   Updated: 2023/12/19 16:30:59 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack get_min(t_listx *lista, int range, int *pos)
{
    (void)range;
    t_stack *stacka;

    if (lista->ptrbegin)
    {
        *pos = 0;
        stacka = lista->ptrbegin;
        while (stacka->number >= 25)
        {
            stacka = stacka->next;
            *pos = *pos + 1;
        }
    }
}