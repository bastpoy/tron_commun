/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 23:24:44 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/07 12:00:53 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstclear(t_list1 **lst, void (*del)(void *))
{
	t_list1 *buffer;

	if (!del)
		return;
	if (lst)
	{
		while (*lst)
		{
			buffer = (*lst)->next;
			del((*lst)->content);
			free(*lst);
			*lst = buffer;
		}
	}
}
