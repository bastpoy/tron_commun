/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:36:41 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/18 11:03:16 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void ft_del_front(t_listx *listx)
{
	t_stack *el;

	if (!listx)
		ft_printf("cant free NULL ptr");
	el = listx->ptrbegin;
	listx->ptrbegin = listx->ptrbegin->next;
	if (listx->ptrbegin)
		listx->ptrbegin->prev = NULL;
	free(el);
}

void ft_del_back(t_listx *listx)
{
	t_stack *current;
	t_stack *previous;

	current = listx->ptrbegin;
	previous = NULL;
	while (current->next != NULL)
	{
		previous = current;
		current = current->next;
	}
	previous->next = NULL;
	free(current);
}

int ft_free_list(t_listx *list)
{
	t_stack *stacka;
	t_stack *tmp;
	int i = 0;

	if (!list)
		return (0);
	stacka = list->ptrbegin;
	printf("je rentre\n");
	while (stacka)
	{
		tmp = stacka;
		printf("i vaut %d\n", i);
		stacka = stacka->next;
		i++;
		free(tmp);
	}
	free(list);
	return (1);
}

t_stack *ft_get_last(t_listx *listx)
{
	t_stack *stackx;

	stackx = listx->ptrbegin;
	while (stackx)
	{
		if (stackx->next == NULL)
			return (stackx);
		else
			stackx = stackx->next;
	}
	return (stackx);
}
