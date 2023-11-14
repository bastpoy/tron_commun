/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 00:03:58 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/14 14:17:35 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*begin;

	if (!lst || !f || !del)
		return (0);
	ptr = malloc(sizeof(t_list) * ft_lstsize(lst));
	if (!ptr)
		return (0);
	ptr = (ft_lstnew(f(lst->content)));
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
