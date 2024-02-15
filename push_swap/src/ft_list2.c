/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:54:22 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/15 18:55:29 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_listx	*ft_init_listx(void)
{
	t_listx	*lista;

	lista = malloc(sizeof(t_listx));
	lista->ptrbegin = NULL;
	return (lista);
}

int	ft_print_listx(t_listx *list)
{
	t_stack	*el;

	if (!list)
		return (0);
	el = list->ptrbegin;
	while (el)
	{
		ft_printf("valeur %d adresse %p\n", el->number, el);
		el = el->next;
	}
	printf("\n");
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

void	ft_insert_front(t_listx *listx, int nb)
{
	t_stack	*stackx;

	stackx = malloc(sizeof(t_stack));
	stackx->number = nb;
	stackx->next = listx->ptrbegin;
	listx->ptrbegin = stackx;
}

void	ft_insert_back(t_listx *listx, int nb)
{
	t_stack	*stackx;

	stackx = ft_get_last(listx);
	stackx->next = malloc(sizeof(t_stack));
	stackx->next->number = nb;
	stackx->next->next = NULL;
}
