/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:54:00 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/07 12:00:41 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd_back(t_list1 **lst, t_list1 *new)
{
	t_list1 *ptr;

	if (!new)
		return;
	if (lst)
	{
		if (*lst == 0)
			*lst = new;
		else
		{
			ptr = ft_lstlast(*lst);
			ptr->next = new;
		}
	}
}
