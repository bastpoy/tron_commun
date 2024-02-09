/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:49:05 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/07 12:01:07 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list1 *ft_lstlast(t_list1 *lst)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (!(lst->next))
		{
			return (lst);
		}
		else
			lst = lst->next;
	}
	return (0);
}
