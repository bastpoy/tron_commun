/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 16:04:47 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/17 21:34:45 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_check_if_sort(t_listx *lista)
{
	t_stack	*stacka;

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

void	algo_two(t_listx *lista)
{
	t_stack	*stacka;

	stacka = lista->ptrbegin;
	if (stacka->number > stacka->next->number)
		ft_ra(lista);
}

void	algo_three(t_listx *lista)
{
	t_stack	*first;
	int		second;
	int		third;

	first = lista->ptrbegin;
	second = first->next->number;
	third = first->next->next->number;
	if (first->number > second && second > third)
	{
		ft_sa(lista);
		ft_rra(lista);
	}
	else if (second > third && third > first->number)
	{
		ft_sa(lista);
		ft_ra(lista);
	}
	else if (first->number > third && third > second)
		ft_ra(lista);
	else if (third > first->number && first->number > second)
		ft_sa(lista);
	else if (second > first->number && first->number > third)
		ft_rra(lista);
}

void	algo_five(t_listx *lista)
{
	int		count;
	t_listx	*listb;

	listb = ft_init_listx();
	ft_pb(lista, listb);
	if (ft_size_listx(lista) == 4)
		ft_pb(lista, listb);
	algo_three(lista);
	while (listb->ptrbegin)
	{
		if (!ft_put_minmax_stack1(listb, lista))
		{
			count = ft_count_rrb(listb, lista);
			ft_rra_or_ra(count, listb, lista);
		}
	}
	ft_free_list(listb);
}

void	algo_radix(t_listx *lista)
{
	t_listx	*listb;
	t_stack	*stacka;
	int		*tab;
	int		i;

	i = 0;
	stacka = lista->ptrbegin;
	listb = ft_init_listx();
	tab = malloc(sizeof(int) * ft_size_listx(lista) + 1);
	if (!tab)
		error(lista);
	while (stacka)
	{
		tab[i] = stacka->number;
		stacka = stacka->next;
		i++;
	}
	i = 0;
	tab = selectionSort(tab, ft_size_listx(lista));
	affect_binary(lista, tab);
	do_radix(lista, listb);
	free(listb);
	free(tab);
}
