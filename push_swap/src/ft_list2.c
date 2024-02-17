/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:54:22 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/17 13:24:29 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_listx *ft_init_listx(void)
{
	t_listx *list;

	list = malloc(sizeof(t_listx));
	if (!list)
		exit(EXIT_FAILURE);
	list->ptrbegin = NULL;
	return (list);
}

int ft_print_listx(t_listx *list)
{
	t_stack *el;

	if (!list)
		return (0);
	el = list->ptrbegin;
	while (el)
	{
		ft_printf("valeur %d adresse %p\n", el->number, el);
		el = el->next;
	}
	ft_printf("\n");
	return (1);
}

int ft_size_listx(t_listx *listx)
{
	t_stack *stackx;
	int count;

	count = 0;
	stackx = listx->ptrbegin;
	while (stackx != NULL)
	{
		stackx = stackx->next;
		count++;
	}
	return (count);
}

void ft_insert_front(t_listx *listx, int nb)
{
	t_stack *stackx;

	stackx = malloc(sizeof(t_stack));
	if (!stackx)
	{
		ft_free_list(listx);
		exit(EXIT_FAILURE);
	}
	stackx->number = nb;
	stackx->next = listx->ptrbegin;
	stackx->prev = NULL;
	if (stackx->next)
		stackx->next->prev = stackx;
	listx->ptrbegin = stackx;
}

void ft_insert_back(t_listx *listx, int nb)
{
	t_stack *stackx;

	stackx = ft_get_last(listx);
	if (!stackx)
	{
		ft_free_list(listx);
		exit(EXIT_FAILURE);
	}
	stackx->next = malloc(sizeof(t_stack));
	stackx->next->number = nb;
	stackx->next->prev = stackx;
	stackx->next->next = NULL;
}
