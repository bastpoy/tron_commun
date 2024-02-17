/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:08:47 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/17 21:26:56 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_first_insert_listb(t_listx *lista, t_listx *listb)
{
	t_stack	*stackb;

	stackb = listb->ptrbegin;
	if (!stackb)
	{
		ft_pb(lista, listb);
	}
}

void	ft_second_insert_listb(t_listx *lista, t_listx *listb)
{
	t_stack	*stackb;

	stackb = listb->ptrbegin;
	if (!stackb->next)
	{
		ft_pb(lista, listb);
		stackb = listb->ptrbegin;
		if (stackb->number < stackb->next->number)
			ft_sb(listb);
	}
}

void	ft_rra_or_ra(int count, t_listx *listb, t_listx *lista)
{
	int	i;
	int	sizea;

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

int	ft_count_rrb(t_listx *listb, t_listx *lista)
{
	t_stack	*stackb;
	t_stack	*stacka;
	int		count;

	stackb = listb->ptrbegin;
	stacka = lista->ptrbegin;
	count = 1;
	while (stacka && stacka->next)
	{
		if (stackb->number > stacka->number
			&& stackb->number < stacka->next->number)
		{
			return (count);
		}
		count++;
		stacka = stacka->next;
	}
	return (1);
}

int	ft_put_minmax_stack1(t_listx *listb, t_listx *lista)
{
	t_stack	*stackb;
	t_stack	*stacka;
	t_stack	*temp;

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
