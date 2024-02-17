/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increment2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:03:39 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/17 14:46:26 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int do_ra_filt_rra(t_listx *lista, t_listx *listb, int i, int count)
{
	while (i != count)
	{
		ft_ra(lista);
		i++;
	}
	pb_filter(lista, listb);
	return (i);
}

void do_rra_filt_ra(t_listx *lista, t_listx *listb, int i, int count)
{
	int sizea;

	sizea = ft_size_listx(lista);
	while (i != (sizea)-count)
	{
		ft_rra(lista);
		i++;
	}
	i++;
	pb_filter(lista, listb);
}

int min_max(t_stack *stacka, t_stack *stackb, t_listx *lista, t_listx *listb)
{
	int count;

	count = 1;
	while (stackb && stackb->next)
	{
		if (stacka->number < stackb->number && stacka->number > stackb->next->number)
		{
			ft_rrb_or_rb(count, lista, listb);
			return (1);
		}
		count++;
		stackb = stackb->next;
	}
	return (0);
}
