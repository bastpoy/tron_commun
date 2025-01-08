/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:46:28 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/17 20:54:46 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_rr(t_listx *lista, t_listx *listb)
{
	if (lista->ptrbegin && lista->ptrbegin->next && listb->ptrbegin
		&& listb->ptrbegin->next)
	{
		ft_insert_back(lista, lista->ptrbegin->number, lista->ptrbegin->bin);
		ft_del_front(lista);
		ft_insert_back(listb, listb->ptrbegin->number, lista->ptrbegin->bin);
		ft_del_front(listb);
		ft_printf("rr");
		return (1);
	}
	else
	{
		ft_printf("error on rr\n");
		return (0);
	}
}

int	ft_rra(t_listx *lista)
{
	t_stack	*stacka;

	if (lista->ptrbegin && lista->ptrbegin->next)
	{
		stacka = ft_get_last(lista);
		ft_insert_front(lista, stacka->number, stacka->bin);
		ft_del_back(lista);
		ft_printf("rra\n");
		return (1);
	}
	else
	{
		ft_printf("error on rra\n");
		return (0);
	}
}

int	ft_rrb(t_listx *listb)
{
	t_stack	*stackb;

	if (listb->ptrbegin && listb->ptrbegin->next)
	{
		stackb = ft_get_last(listb);
		ft_insert_front(listb, stackb->number, stackb->bin);
		ft_del_back(listb);
		ft_printf("rrb\n");
		return (1);
	}
	else
	{
		ft_printf("error on rrb\n");
		return (0);
	}
}

int	ft_rrr(t_listx *lista, t_listx *listb)
{
	t_stack	*stacka;
	t_stack	*stackb;

	if (lista->ptrbegin && lista->ptrbegin->next && listb->ptrbegin
		&& listb->ptrbegin->next)
	{
		stacka = ft_get_last(lista);
		stackb = ft_get_last(listb);
		ft_insert_front(lista, stacka->number, stacka->bin);
		ft_del_back(lista);
		ft_insert_front(listb, stackb->number, stacka->bin);
		ft_del_back(listb);
		ft_printf("rrr\n");
		return (1);
	}
	else
	{
		ft_printf("error on rrr\n");
		return (0);
	}
}
