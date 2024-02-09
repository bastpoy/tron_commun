/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:58:32 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/07 12:01:19 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list1 *ft_lstnew(void *content)
{
	t_list1 *ptr;

	ptr = malloc(sizeof(t_list1));
	if (!ptr)
		return (NULL);
	ptr->content = content;
	ptr->next = 0;
	return (ptr);
}
