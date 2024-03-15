/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:35:48 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/07 12:01:23 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list1 *lst)
{
	size_t	count;

	count = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}
