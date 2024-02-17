/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:54:22 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/17 21:35:24 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_listx	*ft_init_listx(void)
{
	t_listx	*list;

	list = malloc(sizeof(t_listx));
	if (!list)
		exit(EXIT_FAILURE);
	list->ptrbegin = NULL;
	return (list);
}

int	ft_print_listx(t_listx *list)
{
	t_stack	*el;

	if (!list)
		return (0);
	el = list->ptrbegin;
	while (el)
	{
		ft_printf("valeur %d bin %d\n", el->number, el->bin);
		el = el->next;
	}
	ft_printf("\n");
	return (1);
}

int	ft_size_listx(t_listx *listx)
{
	t_stack	*stackx;
	int		count;

	count = 0;
	stackx = listx->ptrbegin;
	while (stackx != NULL)
	{
		stackx = stackx->next;
		count++;
	}
	return (count);
}

void	ft_insert_front(t_listx *listx, int nb, int bin)
{
	t_stack	*stackx;

	stackx = malloc(sizeof(t_stack));
	if (!stackx)
		error(listx);
	stackx->number = nb;
	stackx->bin = bin;
	stackx->next = listx->ptrbegin;
	stackx->prev = NULL;
	if (stackx->next)
		stackx->next->prev = stackx;
	listx->ptrbegin = stackx;
}

void	ft_insert_back(t_listx *listx, int nb, int bin)
{
	t_stack	*stackx;

	stackx = ft_get_last(listx);
	if (!stackx)
		error(listx);
	stackx->next = malloc(sizeof(t_stack));
	stackx->next->number = nb;
	stackx->next->bin = bin;
	stackx->next->prev = stackx;
	stackx->next->next = NULL;
}
