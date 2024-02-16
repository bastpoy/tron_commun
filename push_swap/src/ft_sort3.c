/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:47:34 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/16 10:14:50 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int ft_pa(t_listx *lista, t_listx *listb)
{
	int tmp;

	if (listb->ptrbegin)
	{
		tmp = listb->ptrbegin->number;
		ft_insert_front(lista, tmp);
		ft_del_front(listb);
		ft_printf("pa\n");
		return (1);
	}
	else
	{
		ft_printf("error on pa\n");
		return (0);
	}
}

int ft_pb(t_listx *lista, t_listx *listb)
{
	int tmp;

	if (lista->ptrbegin)
	{
		tmp = lista->ptrbegin->number;
		ft_insert_front(listb, tmp);
		ft_del_front(lista);
		ft_printf("pb\n");
		return (1);
	}
	else
	{
		ft_printf("error on pb\n");
		return (0);
	}
}

int ft_ra(t_listx *lista)
{
	if (lista->ptrbegin && lista->ptrbegin->next)
	{
		ft_insert_back(lista, lista->ptrbegin->number);
		ft_del_front(lista);
		ft_printf("ra\n");
		return (1);
	}
	else
	{
		ft_printf("error on ra\n");
		return (0);
	}
}

int ft_rb(t_listx *listb)
{
	if (listb->ptrbegin && listb->ptrbegin->next)
	{
		ft_insert_back(listb, listb->ptrbegin->number);
		ft_del_front(listb);
		ft_printf("rb\n");
		return (1);
	}
	else
	{
		ft_printf("error on rb\n");
		return (0);
	}
}
