/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:07:28 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/16 10:13:33 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int ft_sa(t_listx *lista)
{
	int tmp;

	if (lista->ptrbegin && lista->ptrbegin->next)
	{
		tmp = lista->ptrbegin->number;
		lista->ptrbegin->number = lista->ptrbegin->next->number;
		lista->ptrbegin->next->number = tmp;
		ft_printf("sa\n");
		return (1);
	}
	else
	{
		ft_printf("error on sa\n");
		return (0);
	}
}

int ft_sb(t_listx *listb)
{
	int tmp;

	if (listb->ptrbegin && listb->ptrbegin->next)
	{
		tmp = listb->ptrbegin->number;
		listb->ptrbegin->number = listb->ptrbegin->next->number;
		listb->ptrbegin->next->number = tmp;
		ft_printf("sb\n");
		return (1);
	}
	else
	{
		ft_printf("error on sb\n");
		return (0);
	}
}

int ft_ss(t_listx *lista, t_listx *listb)
{
	int tmp1;
	int tmp2;

	if (lista->ptrbegin && lista->ptrbegin->next && listb->ptrbegin && listb->ptrbegin->next)
	{
		tmp1 = lista->ptrbegin->number;
		lista->ptrbegin->number = lista->ptrbegin->next->number;
		lista->ptrbegin->next->number = tmp1;
		tmp2 = listb->ptrbegin->number;
		listb->ptrbegin->number = listb->ptrbegin->next->number;
		listb->ptrbegin->next->number = tmp2;
		ft_printf("ss\n");
		return (1);
	}
	else
	{
		ft_printf("error on ss\n");
		return (0);
	}
}
