/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:08:47 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/17 11:40:56 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void ft_first_insert_listb(t_listx *lista, t_listx *listb)
{
	t_stack *stackb;

	stackb = listb->ptrbegin;
	if (!stackb)
	{
		ft_pb(lista, listb);
	}
}

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

void ft_rrb_or_rb(int count, t_listx *lista, t_listx *listb)
{
	int i;
	int sizeb;

	i = 0;
	sizeb = ft_size_listx(listb);
	if (count <= (sizeb) / 2)
	{
		i = do_rb_rrb(lista, listb, count, i);
	}
	else
	{
		do_rrb_rb(lista, listb, count, i);
	}
}

void ft_rra_or_ra(int count, t_listx *listb, t_listx *lista)
{
	int i;
	int sizea;

	i = 0;
	sizea = ft_size_listx(lista);
	if (count <= (sizea) / 2)
	{
		i = do_ra_rra(lista, listb, count, i);
	}
	else
	{
		do_rra_ra(lista, listb, count, i);
	}
}

void ft_rra_ra_pb(int count, t_listx *listb, t_listx *lista)
{
	int i;
	int sizea;

	i = 0;
	sizea = ft_size_listx(lista);
	if (count <= (sizea) / 2)
	{
		i = do_ra_filt_rra(lista, listb, i, count);
	}
	else
	{
		do_rra_filt_ra(lista, listb, i, count);
	}
}
