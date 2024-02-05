/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:13:05 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/05 18:24:45 by bpoyet           ###   ########.fr       */
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

int	ft_free_list(t_list *lista)
{
	t_line	*stacka;
	t_line	*tmp;

	stacka = lista->ptrbegin;
	if (!lista)
		return (0);
	while (stacka != NULL)
	{
		tmp = stacka;
		stacka = stacka->next;
		free(tmp);
	}
	free(lista);
	return (1);
}
