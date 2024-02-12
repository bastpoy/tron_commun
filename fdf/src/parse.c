/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 22:11:04 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/12 11:51:58 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// static char *checkbackn(char *str)
// {
// 	int i;
// 	i = 0;
// 	if (str == NULL)
// 	{
// 		return (0);
// 	}
// 	while (str[i] != '\0')
// 	{
// 		if (str[0] == '\n')
// 		{
// 			str = NULL;
// 			break;
// 		}
// 		if (str[i] == '\n' && str[i - 1] == ' ')
// 		{
// 			str[i - 1] = '\0';
// 		}
// 		if (str[i] == '\n')
// 		{
// 			str[i] = '\0';
// 		}
// 		i++;
// 	}
// 	return (str);
// }

static char **read_line(char *str)
{
	char **strsplit;

	strsplit = ft_split(str, '\n');
	free(str);
	return (strsplit);
}

static char ***read_space(char **strsplit, t_input input)
{
	char ***splitspace;
	int i;

	i = 0;
	splitspace = (char ***)malloc(sizeof(char **) * (input.ord + 1));
	if (!splitspace)
	{
		ft_free_entrystr(strsplit);
		ft_return_error("Malloc Error");
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

static char ***read_file(char *entry, t_input input)
{
	int fd;
	char *str;
	char *tmp;
	char *old_str;
	char **strsplit;
	char ***strspace;

	str = NULL;
	fd = open(entry, O_RDONLY);
	if (fd < 0)
		ft_return_error("cannot open file");
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
	strsplit = read_line(str);
	strspace = read_space(strsplit, input);
	return (strspace);
}

static int ft_hex_to_int(char *str)
{
	int output;
	int i;
	int x;

	i = 7;
	output = 0;
	while (i >= 2)
	{
		if (str[i] >= '0' && str[i] <= '9')
			x = (str[i] - '0');
		else if (str[i] >= 'A' && str[i] <= 'F')
			x = (str[i] - 'A' + 10);
		else
			x = (str[i] - 'a' + 10);
		output = output + x * pow(16, i - 2);
		i--;
	}
	return (output);
}

static t_map ***ft_input_str_coma(char ***str, t_map ***point, t_input input, int i)
{
	char **strsplit;
	int j;

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

t_map ***ft_fill_struct(t_input input, char *entry)
{
	char ***str;
	t_map ***map;
	int i;

	i = 0;
	str = read_file(entry, input);
	map = (t_map ***)malloc(sizeof(t_map **) * (input.ord + 1)); // j'alloue mon nombre de lignes
	if (!map)
	{
		free_ptrptrptr(str);
		ft_return_error("Malloc Error");
	}
	// i represente mon nombre de lignes
	while (str[i])
	{
		ft_input_str_coma(str, map, input, i);
		i++;
	}
	free_ptrptrptr(str);
	map[i] = NULL;
	return (map);
}
