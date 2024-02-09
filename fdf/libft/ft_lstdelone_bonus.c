/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:18:55 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/07 12:00:58 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstdelone(t_list1 *lst, void (*del)(void *))
{
	if (!lst || !del)
		return;
	if (lst)
		(*del)(lst->content);
	free(lst);
}
