/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:07:28 by bpoyet            #+#    #+#             */
/*   Updated: 2023/12/20 10:38:01 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		printf("error on ra\n");
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
		printf("error on ra\n");
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
		printf("error on ra\n");
		return (0);
	}
}

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
		printf("error on ra\n");
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
		printf("error on ra\n");
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
		printf("error on ra\n");
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
		printf("error on rb\n");
		return (0);
	}
}

int ft_rr(t_listx *lista, t_listx *listb)
{
	if (lista->ptrbegin && lista->ptrbegin->next && listb->ptrbegin && listb->ptrbegin->next)
	{
		ft_insert_back(lista, lista->ptrbegin->number);
		ft_del_front(lista);
		ft_insert_back(listb, listb->ptrbegin->number);
		ft_del_front(listb);
		ft_printf("rr");
		return (1);
	}
	else
	{
		printf("error on rr\n");
		return (0);
	}
}

int ft_rra(t_listx *lista)
{
	t_stack *stacka;
	if (lista->ptrbegin && lista->ptrbegin->next)
	{
		stacka = ft_get_last(lista);
		ft_insert_front(lista, stacka->number);
		ft_del_back(lista);
		ft_printf("rra\n");
		return (1);
	}
	else
	{
		printf("error on rra\n");
		return (0);
	}
}

int ft_rrb(t_listx *listb)
{
	t_stack *stackb;
	if (listb->ptrbegin && listb->ptrbegin->next)
	{
		stackb = ft_get_last(listb);
		ft_insert_front(listb, stackb->number);
		ft_del_back(listb);
		ft_printf("rrb\n");
		return (1);
	}
	else
	{
		printf("error on ra\n");
		return (0);
	}
}

int ft_rrr(t_listx *lista, t_listx *listb)
{
	t_stack *stacka;
	t_stack *stackb;

	if (lista->ptrbegin && lista->ptrbegin->next && listb->ptrbegin && listb->ptrbegin->next)
	{
		stacka = ft_get_last(lista);
		stackb = ft_get_last(listb);
		ft_insert_front(lista, stacka->number);
		ft_del_back(lista);
		ft_insert_front(listb, stackb->number);
		ft_del_back(listb);
		ft_printf("rrr\n");
		return (1);
	}
	else
	{
		printf("error on ra\n");
		return (0);
	}
}