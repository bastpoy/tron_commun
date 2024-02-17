/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:56:03 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/17 17:12:46 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int ft_max_listx(t_listx *listx)
{
	t_stack *stackx;
	int temp;

	stackx = listx->ptrbegin;
	if (!stackx)
		return (0);
	temp = stackx->number;
	while (stackx)
	{
		if (stackx->number > temp)
			temp = stackx->number;
		stackx = stackx->next;
	}
	return (temp);
}

int ft_min_listx(t_listx *listx)
{
	t_stack *stackx;
	int temp;

	stackx = listx->ptrbegin;
	if (!stackx)
		return (0);
	temp = stackx->number;
	while (stackx)
	{
		if (stackx->number < temp)
			temp = stackx->number;
		stackx = stackx->next;
	}
	return (temp);
}

int ft_getnumber_list(t_listx *listx, int min, int max)
{
	t_stack *stackx;
	int count;

	int count2 = 0;
	count = 0;
	stackx = listx->ptrbegin;
	// printf("min %d et max %d\n", min, max);
	while (stackx && (stackx->number < min || stackx->number > max))
	{
		count++;
		stackx = stackx->next;
	}
	stackx = ft_get_last(listx);
	while (stackx && (stackx->number < min || stackx->number > max))
	{
		count2++;
		stackx = stackx->prev;
	}
	if (stackx && stackx->number >= min && stackx->number <= max)
	{
		// printf("count %d et count2 %d\n", count, count2);
		if (count > count2)
		{
			return (ft_size_listx(listx) - (count2 + 1));
		}
		else
			return (count);
	}
	return (-1);
}

int num_max_min(t_listx *lista, t_listx *listb)
{
	t_stack *stacka;
	t_stack *stackb;

	stacka = lista->ptrbegin;
	stackb = listb->ptrbegin;
	// if (stackb && stacka->number > ft_max_listx(listb))
	// 	return (1);
	// if (stackb && stacka->number < ft_min_listx(listb))
	// 	return (0);
	if (stackb && stacka->number > ft_max_listx(listb))
		return (1);
	if (stackb && stacka->number < ft_min_listx(listb))
		return (0);
	return (-1);
}
