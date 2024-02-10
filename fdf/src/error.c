/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:37:16 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/10 17:14:32 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void ft_return_error(char *err_msg)
{
	perror(err_msg);
	exit(-1);
}

void print_map(t_map ***map)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			printf("map x %d y %d et z %d\n", map[i][j]->x, map[i][j]->y, map[i][j]->z);
			j++;
		}
		i++;
	}
}

void error_map(char *err_msg, t_map ***map)
{
	free(map);
	perror(err_msg);
	exit(-1);
}

void error_point(char *err_msg, t_map ***map, int max)
{
	free(map[max]);
	free(map);
	perror(err_msg);
	exit(-1);
}