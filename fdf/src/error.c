/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:37:16 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/13 19:37:28 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void ft_return_error(char *err_msg)
{
	write(1, err_msg, ft_strlen(err_msg));
	exit(-1);
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

int error_openfile(char *entry)
{
	char **split;
	int i;
	int size;

	i = 0;
	split = ft_split(entry, '/');
	if (!split)
		return (0);
	while (split[i])
		i++;
	size = ft_strlen(split[i - 1]);
	if (!ft_strnstr(split[i - 1], ".fdf", size))
		return (0);
	return (1);
}
