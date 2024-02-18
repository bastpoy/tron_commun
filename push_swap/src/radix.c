/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 21:28:20 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/18 10:48:49 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void affect_binary(t_listx *lista, int *tab)
{
	t_stack *stacka;
	int i;

	i = 0;
	stacka = lista->ptrbegin;
	while (stacka)
	{
		while (tab[i] != stacka->number)
		{
			i++;
		}
		stacka->bin = i;
		stacka = stacka->next;
		i = 0;
	}
}

void do_radix(t_listx *lista, t_listx *listb)
{
	t_stack *stacka;
	int max_bits;
	int i;
	int j;
	int size;

	i = 0;
	size = ft_size_listx(lista);
	max_bits = sizeof(int) * 8;
	while (i < max_bits && !ft_check_if_sort(lista))
	{
		j = 0;
		while (j < size)
		{
			stacka = lista->ptrbegin;
			if (((stacka->bin >> i) & 1) == 1)
				ft_ra(lista);
			else
				ft_pb(lista, listb);
			j++;
		}
		while (listb->ptrbegin != NULL)
			ft_pa(lista, listb);
		i++;
	}
}

int *selection_sort(int *tab, int n)
{
	int i;
	int min_idx;
	int j;
	int temp;

	i = 0;
	while (i < n - 1)
	{
		min_idx = i;
		j = i + 1;
		while (j < n)
		{
			if (tab[j] < tab[min_idx])
				min_idx = j;
			j++;
		}
		temp = tab[min_idx];
		tab[min_idx] = tab[i];
		tab[i] = temp;
		i++;
	}
	return (tab);
}
