/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:22:52 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/16 16:57:15 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*begin;

	if (!lst || !f || !del)
		return (0);
	ptr = (ft_lstnew(f(lst->content)));
	if (!ptr)
		return (0);
	begin = ptr;
	lst = lst->next;
	if (lst)
	{
		while (lst != NULL)
		{
			ptr->next = ft_lstnew(f(lst->content));
			ptr = ptr->next;
			lst = lst->next;
		}
	}
	(*del)(lst);
	free(lst);
	return (begin);
}
