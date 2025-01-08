/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:13:05 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/13 15:08:03 by bpoyet           ###   ########.fr       */
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
	}
	free(str);
}

void	free_float(float *q, float *p)
{
	free(q);
	free(p);
}

void	free_ptrptrptr(char ***str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str)
	{
		while (str[i])
		{
			j = 0;
			while (str[i][j])
			{
				free(str[i][j]);
				j++;
			}
			free(str[i]);
			i++;
		}
		free(str);
	}
}

void	free_map(t_map ***map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (map)
	{
		while (map[i])
		{
			j = 0;
			while (map[i][j])
			{
				free(map[i][j]);
				j++;
			}
			free(map[i]);
			i++;
		}
		free(map);
	}
}
