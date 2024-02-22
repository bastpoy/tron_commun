/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 22:11:04 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/13 19:39:07 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static char	**read_line(char *str)
{
	char	**strsplit;

	strsplit = ft_split(str, '\n');
	free(str);
	return (strsplit);
}

static char	***read_space(char **strsplit, t_input input)
{
	char	***splitspace;
	int		i;

	i = 0;
	splitspace = (char ***)malloc(sizeof(char **) * (input.ord + 1));
	if (!splitspace)
	{
		ft_free_entrystr(strsplit);
		ft_return_error("Malloc Error\n");
	}
	while (strsplit[i] != NULL)
	{
		splitspace[i] = ft_split(strsplit[i], ' ');
		i++;
	}
	splitspace[i] = NULL;
	ft_free_entrystr(strsplit);
	return (splitspace);
}

static char	***read_file(char *entry, t_input input)
{
	int		fd;
	char	*str;
	char	*tmp;
	char	*old_str;
	char	***strspace;

	str = NULL;
	fd = open(entry, O_RDONLY);
	if (fd < 0)
		ft_return_error("cannot open file\n");
	tmp = get_next_line(fd);
	while (tmp)
	{
		old_str = str;
		str = ft_strjoin(str, tmp);
		free(tmp);
		free(old_str);
		tmp = get_next_line(fd);
	}
	close(fd);
	strspace = read_space(read_line(str), input);
	return (strspace);
}

static t_map	***ft_input_str_coma(char ***str, t_map ***point, t_input input,
		int i)
{
	char	**strsplit;
	int		j;

	j = 0;
	point[i] = (t_map **)malloc(sizeof(t_map *) * (input.abs + 1));
	if (!point[i])
		error_map("Malloc error", point);
	while (str[i][j])
	{
		point[i][j] = (t_map *)malloc(sizeof(t_map));
		if (!point[i][j])
			error_point("Malloc error", point, i);
		point[i][j]->x = j;
		point[i][j]->y = i;
		strsplit = ft_split(str[i][j], ',');
		point[i][j]->z = ft_atoi(strsplit[0]);
		if (strsplit[1])
			point[i][j]->color = ft_hex_to_int(strsplit[1]);
		else
			point[i][j]->color = 0xffffff;
		ft_free_entrystr(strsplit);
		j++;
	}
	point[i][j] = NULL;
	return (point);
}

t_map	***ft_fill_struct(t_input input, char *entry)
{
	char	***str;
	t_map	***map;
	int		i;

	i = 0;
	str = read_file(entry, input);
	map = (t_map ***)malloc(sizeof(t_map **) * (input.ord + 1));
	if (!map)
	{
		free_ptrptrptr(str);
		ft_return_error("Malloc Error\n");
	}
	while (str[i])
	{
		ft_input_str_coma(str, map, input, i);
		i++;
	}
	free_ptrptrptr(str);
	map[i] = NULL;
	return (map);
}
