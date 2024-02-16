/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:56:03 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/16 10:08:47 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_max_listx(t_listx *listx)
{
	t_stack	*stackx;
	int		temp;

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

int	ft_min_listx(t_listx *listx)
{
	t_stack	*stackx;
	int		temp;

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

int	ft_getnumber_list(t_listx *listx, int min, int max)
{
	int		count;
	t_stack	*stackx;

	count = 0;
	stackx = listx->ptrbegin;
	while (stackx && (stackx->number < min || stackx->number > max))
	{
		count++;
		stackx = stackx->next;
	}
	if (stackx && stackx->number >= min && stackx->number <= max)
	{
		return (count);
	}
	return (-1);
}

int	num_max_min(t_listx *lista, t_listx *listb)
{
	t_stack	*stacka;
	t_stack	*stackb;

	stacka = lista->ptrbegin;
	stackb = listb->ptrbegin;
	if (stackb && stacka->number > ft_max_listx(listb))
		return (1);
	if (stackb && stacka->number < ft_min_listx(listb))
		return (0);
	return (-1);
}
