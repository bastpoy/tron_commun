/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:12:30 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/17 21:26:04 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
