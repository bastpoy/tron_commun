/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:13:05 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/06 12:41:39 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_free_entrystr(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str[i]);
		free(str);
	}
}

void	free_float(float *q, float *p)
{
	free(q);
	free(p);
}

int	ft_free_list(t_list *list)
{
	t_line	*stacka;
	t_line	*tmp;

	stacka = list->ptrbegin;
	if (!list)
		return (0);
	while (stacka)
	{
		tmp = stacka;
		stacka = stacka->next;
		free(tmp);
	}
	list->ptrbegin = NULL;
	list->data = NULL;
	free(list);
	return (1);
}
