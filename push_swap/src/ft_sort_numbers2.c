/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_numbers2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:57:42 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/17 14:44:37 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int ft_count_rrb(t_listx *listb, t_listx *lista)
{
	t_stack *stackb;
	t_stack *stacka;
	int count;

	stackb = listb->ptrbegin;
	stacka = lista->ptrbegin;
	count = 1;
	while (stacka && stacka->next)
	{
		if (stackb->number > stacka->number && stackb->number < stacka->next->number)
		{
			return (count);
		}
		count++;
		stacka = stacka->next;
	}
	return (1);
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

int pb_filter(t_listx *lista, t_listx *listb)
{
	t_stack *stacka;
	t_stack *stackb;
	int minmax;

	stacka = lista->ptrbegin;
	stackb = listb->ptrbegin;
	minmax = num_max_min(lista, listb);
	if (stackb)
	{
		if (minmax == 0)
			return (ft_pb(lista, listb), ft_rb(listb), 1);
		if (minmax == 1)
			return (ft_pb(lista, listb), 1);
		return (min_max(stacka, stackb, lista, listb));
	}
	else
		ft_pb(lista, listb);
	return (0);
}
