/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 22:11:04 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/09 19:15:07 by bpoyet           ###   ########.fr       */
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

// static void print_split(char ***str)
// {
// 	int i = 0;
// 	int j = 0;
// 	int k = 0;

// 	while (str[i][j])
// 	{
// 		k = 0;
// 		while (str[i][j][k])
// 		{
// 			printf("%d et k -%d-\n", str[i][j][k], k);
// 			k++;
// 		}
// 		printf("j vaut %d\n", j);
// 		j++;
// 	}
// }

static char **read_line(char *str)
{
	char **strsplit;

	strsplit = ft_split(str, '\n');
	return (strsplit);
}

static char ***res_space(char **strsplit, t_input input)
{
	char ***splitspace;
	int i;

	i = 0;
	splitspace = (char ***)malloc(sizeof(char **) * (input.ord));
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
	char **strsplit;
	char ***strspace;

	str = NULL;
	fd = open(entry, O_RDONLY);
	if (fd < 0)
		ft_return_error("cannot open file");
	tmp = get_next_line(fd);
	while (tmp)
	{
		str = ft_strjoin(str, tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	close(fd);
	strsplit = read_line(str);
	free(str);
	strspace = res_space(strsplit, input);
	// print_split(strspace);
	return (strspace);
}

// static int ft_hex_to_int(char *str)
// {
// 	int output;
// 	int i;
// 	int x;

// 	i = 7;
// 	output = 0;
// 	while (i >= 2)
// 	{
// 		if (str[i] >= '0' && str[i] <= '9')
// 			x = (str[i] - '0');
// 		else if (str[i] >= 'A' && str[i] <= 'F')
// 			x = (str[i] - 'A' + 10);
// 		else
// 			x = (str[i] - 'a' + 10);
// 		output = output + x * pow(16, i - 2);
// 		i--;
// 	}
// 	return (output);
// }

// static char **ft_input_str_space(char *entry)
// {
// 	char *strentry;
// 	char **strsplit;
// 	static int fd = 0;

// 	if (fd == 0)
// 	{
// 		fd = open(entry, O_RDONLY);
// 		if (fd < 0)
// 			ft_return_error("cannot open file");
// 	}
// 	strentry = get_next_line(fd);
// 	strentry = checkbackn(strentry);
// 	if (strentry == NULL)
// 	{
// 		free(strentry);
// 		return (NULL);
// 	}
// 	strsplit = ft_split(strentry, ' ');
// 	free(strentry);
// 	return (strsplit);
// }

// static t_line *ft_input_str_coma(char *str, t_line *point)
// {
// 	int i;
// 	char **strsplit;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == ',')
// 		{
// 			strsplit = ft_split(str, ',');
// 			point->z1 = ft_atoi(strsplit[0]);
// 			point->color = ft_hex_to_int(strsplit[1]);
// 			ft_free_entrystr(strsplit);
// 			return (point);
// 		}
// 		i++;
// 	}
// 	point->z1 = ft_atoi(str);
// 	point->color = MINCOLOR;
// 	return (point);
// }

// t_list *ft_fill_struct(t_list *list, t_input input, char *entry)
// {
// 	int i;
// 	int j;
// 	char **str;
// 	t_line *line;

// 	j = 1;
// 	read_file(entry, input);
// 	str = ft_input_str_space(entry);
// 	line = ft_init_tline(list);
// 	list->ptrbegin = line;
// 	while (str != NULL && line)
// 	{
// 		i = 0;
// 		while (str[i] != NULL)
// 		{
// 			line = ft_input_str_coma(str[i], line);
// 			line->next = ft_init_tline(list);
// 			line = fill_tline(list, input, line, j);
// 			line = line->next;
// 			i++;
// 			j++;
// 		}
// 		ft_free_entrystr(str);
// 		str = ft_input_str_space(entry);
// 	}
// 	return (list);
// }

// t_list *ft_fill_struct(t_list *list, t_input input, char *entry)
// {
// 	int i;
// 	int j;
// 	int k;
// 	char ***str;
// 	t_line *line;

// 	j = 1;
// 	i = 0;
// 	str = read_file(entry, input);
// 	line = ft_init_tline(list);
// 	list->ptrbegin = line;
// 	while (str[i] != NULL && line)
// 	{
// 		k = 0;
// 		while (str[i][k] != NULL)
// 		{
// 			line = ft_input_str_coma(str[i][k], line);
// 			line->next = ft_init_tline(list);
// 			line = fill_tline(list, input, line, j);
// 			line = line->next;
// 			j++;
// 			k++;
// 		}
// 		i++;
// 	}
// 	free_ptrptrptr(str);
// 	return (list);
// }

static t_line *ft_input_str_coma(char **str, t_input input, int indice)
{
	int i;
	int j;
	char **strsplit;
	t_map **point;

	i = 0;
	j = 0;
	point = (t_map **)malloc(sizeof(t_map *) * input.ord);
	while (str[i])
	{
		while (str[i][j])
		{
			point[i] = malloc(sizeof(t_map) * input.abs);
			point[indice][j].x = j;
			point[indice][j].y = indice;
			if (strchr(str[i], ','))
			{
				strsplit = ft_split(str[i], ',');
				point[indice][j].z = ft_atoi(strsplit[0]);
				point[indice][j].color = ft_hex_to_int(strsplit[1]);
				ft_free_entrystr(strsplit);
			}
			else
			{
				point[indice][j].z = ft_atoi(str[i]);
				point[indice][j].color = MINCOLOR;
			}
				}
		i++;
	}
	return (point);
}

t_list *ft_fill_struct(t_list *list, t_input input, char *entry)
{
	char ***str;
	int i = 0;
	int j = 0;

	str = read_file(entry, input);
	while (str[i])
	{
		ft_input_str_coma(str[i], input, i);
		i++;
	}
	return (list);
}
