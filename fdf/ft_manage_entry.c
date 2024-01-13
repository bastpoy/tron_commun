/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_entry.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:34:50 by bpoyet            #+#    #+#             */
/*   Updated: 2024/01/12 23:12:55 by bpoyet           ###   ########.fr       */
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
    tab = (int ***)malloc(sizeof(int) * input.ord);
    if (!tab)
        return (NULL);
    while (i < input.ord)
    {
        *tab = (int **)malloc(sizeof(int) * input.abs);
        if (!*tab)
            return (NULL);
        while (j < input.abs)
        {
            **tab = (int *)malloc(sizeof(int) * 2);
            if (!**tab)
                return (NULL);
            j++;
        }
        j = 0;
        i++;
    }
    return (tab);
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
    int i;
    int j;
    char *str;
    char **strsplit;

    i = 0;
    fd = open("entry.fdf", O_RDONLY);
    str = get_next_line(fd);
    strsplit = ft_split(str, ' ');

    while (strsplit[i] != NULL)
    {
        j = 0;
        while (strsplit[i][j] != '\0')
        {
            if (strsplit[i][0] == '\n')
                strsplit[i] = NULL;
            else if (strsplit[i][j] == '\n')
                strsplit[i][j] = '\0';
            j++;
        }
        printf("str -%s-\n", strsplit[i]);
        i++;
    }
    return (strsplit);
}
