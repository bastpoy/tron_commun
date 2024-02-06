/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:34:50 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/06 13:42:22 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static char	**ft_entry_backn(char **strsplit)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (strsplit[i] != NULL)
	{
		j = 0;
		while (strsplit[i][j] != '\0')
		{
			if (strsplit[i][0] == '\n')
			{
				strsplit[i] = NULL;
				break ;
			}
			else if (strsplit[i][j] == '\n')
				strsplit[i][j] = '\0';
			j++;
		}
		i++;
	}
	return (strsplit);
}

static int	ft_hex_to_int(char *str)
{
	int	output;
	int	i;
	int	x;

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

static char	**ft_input_str_space(t_list *list, char *entry)
{
	char		*strentry;
	char		**strsplit;
	static int	fd = 0;

	if (fd == 0)
		fd = open(entry, O_RDONLY);
	strentry = get_next_line(fd);
	if (strentry == NULL)
		return (NULL);
	strsplit = ft_split(strentry, ' ');
	strsplit = ft_entry_backn(strsplit);
	free(strentry);
	if (!strsplit)
		list->err = 0;
	return (strsplit);
}

static t_line	*ft_input_str_coma(char *str, t_line *point)
{
	int		i;
	char	**strsplit;

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

t_list	*ft_fill_struct(t_list *list, t_input input, char *entry)
{
	int		i;
	int		j;
	char	**str;
	t_line	*line;

	j = 1;
	str = ft_input_str_space(list, entry);
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
		str = ft_input_str_space(list, entry);
	}
	return (list);
}
