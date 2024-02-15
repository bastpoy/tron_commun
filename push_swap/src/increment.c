/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:12:30 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/15 18:50:49 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	do_rb_rrb(t_listx *lista, t_listx *listb, int count, int i)
{
	while (i != count)
	{
		ft_rb(listb);
		i++;
	}
	ft_pb(lista, listb);
	while (i != 0)
	{
		ft_rrb(listb);
		i--;
	}
	return (i);
}

void	do_rrb_rb(t_listx *lista, t_listx *listb, int count, int i)
{
	int	sizeb;

	sizeb = ft_size_listx(listb);
	while (i != (sizeb)-count)
	{
		ft_rrb(listb);
		i++;
	}
	i++;
	ft_pb(lista, listb);
	while (i != 0)
	{
		ft_rb(listb);
		i--;
	}
}

int	do_ra_rra(t_listx *lista, t_listx *listb, int count, int i)
{
	while (i != count)
	{
		ft_ra(lista);
		i++;
	}
	ft_pa(lista, listb);
	while (i != 0)
	{
		ft_rra(lista);
		i--;
	}
	return (i);
}

void	do_rra_ra(t_listx *lista, t_listx *listb, int count, int i)
{
	int	sizea;

	sizea = ft_size_listx(lista);
	while (i != (sizea)-count)
	{
		ft_rra(lista);
		i++;
	}
	i++;
	ft_pa(lista, listb);
	while (i != 0)
	{
		ft_ra(lista);
		i--;
	}
}
