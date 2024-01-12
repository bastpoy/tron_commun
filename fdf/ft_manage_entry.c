/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_entry.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:34:50 by bpoyet            #+#    #+#             */
/*   Updated: 2024/01/12 19:12:29 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ***ft_malloc_array(t_input input)
{
    int i;
    int j;
    int ***tab;

    i = 0;
    j = 0;
    tab = (int***)malloc(sizeof(int) * input.ord);
    if(!tab)
        return(NULL);
    while(i < input.ord)
    {
        *tab = (int**)malloc(sizeof(int) * input.abs);
        if(!*tab)
            return (NULL);
        while(j < input.abs)
        {
            **tab = (int*)malloc(sizeof(int) * 2);
            if(!**tab)
                return (NULL);
            j++;
        }
        j = 0;
        i++;
    }
    return(tab);
}

size_t ft_strlen_space_backn(const char *str)
{
    size_t i;
    size_t j;

    i = 0;
    j = 0;
    if (!str)
        return (0);
    while (str[i] != '\0')
    {
        if (str[i] != ' ' && str[i] != '\n')
        {
            j++;
        }
        i++;
    }
    return (j);
}

t_input ft_get_length_width()
{
    int fd;
    char *str;
    t_input input;

    fd = open("entry.fdf", O_RDONLY);
    str = get_next_line(fd);
    input.abs = ft_strlen_space_backn(str);
    input.ord = 0;
    while (str)
    {
        input.ord++;
        str = get_next_line(fd);
    }
    close(fd);
    return (input);
}

char **ft_input_str_space()
{
	int fd;
	char *str;
	char **strsplit;

	fd = open("entry.fdf", O_RDONLY);
	str = get_next_line(fd);
	strsplit = ft_split(str, ' ');

	printf("strr %s-\n", str);
	while(*strsplit != NULL)
	{
		printf("str %s\n", *strsplit);
		strsplit++;
	}
	return (strsplit);
}

