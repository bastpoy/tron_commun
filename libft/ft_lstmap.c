/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 00:03:58 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/14 00:15:24 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;

	ptr = malloc(sizeof(t_list) * ft_lstsize(lst + 1));
	if (!ptr)
		return (0);
	if (lst)
	{
		while (lst)
		{
			ptr = lst;
			ptr->content = (*f)(lst->content);
			del(lst->content);
			lst = lst->next;
		}
	}
	free(lst);
	return (ptr);
}
