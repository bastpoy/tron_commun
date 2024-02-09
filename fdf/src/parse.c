/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 22:11:04 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/08 19:17:30 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static char *checkbackn(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
	{
		return (0);
	}
	while (str[i] != '\0')
	{
		if (str[0] == '\n')
		{
			str = NULL;
			break;
		}
		if (str[i] == '\n' && str[i - 1] == ' ')
		{
			str[i - 1] = '\0';
		}
		if (str[i] == '\n')
		{
			str[i] = '\0';
		}
		i++;
	}
	return (str);
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

static char **ft_input_str_space(char *entry)
{
	char *strentry;
	char **strsplit;
	static int fd = 0;

	if (fd == 0)
	{
		fd = open(entry, O_RDONLY);
		if (fd < 0)
			ft_return_error("cannot open file");
	}
	strentry = get_next_line(fd);
	strentry = checkbackn(strentry);
	if (strentry == NULL)
	{
		free(strentry);
		return (NULL);
	}
	strsplit = ft_split(strentry, ' ');
	free(strentry);
	return (strsplit);
}

static t_line *ft_input_str_coma(char *str, t_line *point)
{
	int i;
	char **strsplit;

	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
		{
			strsplit = ft_split(str, ',');
			point->z1 = ft_atoi(strsplit[0]);
			point->color = ft_hex_to_int(strsplit[1]);
			ft_free_entrystr(strsplit);
			return (point);
		}
		i++;
	}
	point->z1 = ft_atoi(str);
	point->color = MINCOLOR;
	return (point);
}

t_list *ft_fill_struct(t_list *list, t_input input, char *entry)
{
	int i;
	int j;
	char **str;
	t_line *line;

	j = 1;
	str = ft_input_str_space(entry);
	line = ft_init_tline(list);
	list->ptrbegin = line;
	while (str != NULL && line)
	{
		i = 0;
		while (str[i] != NULL)
		{
			line = ft_input_str_coma(str[i], line);
			line->next = ft_init_tline(list);
			line = fill_tline(list, input, line, j);
			line = line->next;
			i++;
			j++;
		}
		ft_free_entrystr(str);
		str = ft_input_str_space(entry);
	}
	return (list);
}
