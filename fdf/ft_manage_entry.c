/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_entry.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:34:50 by bpoyet            #+#    #+#             */
/*   Updated: 2024/01/19 15:45:24 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

    fd = open("maps/test_maps/pyramide.fdf", O_RDONLY);
    str = get_next_line(fd);
    input.abs = ft_strlen_space_backn(str);
    input.ord = 0;
    while (str)
    {
        input.ord++;
        free(str);
        str = get_next_line(fd);
    }
    close(fd);
    return (input);
}

char **ft_entry_backn(char **strsplit)
{
    int i;
    int j;

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
                break;
            }
            else if (strsplit[i][j] == '\n')
                strsplit[i][j] = '\0';
            j++;
        }
        i++;
    }
    return (strsplit);
}

int ft_hex_to_int(char *str)
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

char **ft_input_str_space()
{
    char *strentry;
    char **strsplit;
    static int fd = 0;

    if (fd == 0)
        fd = open("maps/test_maps/pyramide.fdf", O_RDONLY);
    strentry = get_next_line(fd);
    if (strentry == NULL)
        return (NULL);
    strsplit = ft_split(strentry, ' ');
    strsplit = ft_entry_backn(strsplit);
    free(strentry);
    return (strsplit);
}

t_line *ft_input_str_coma(char *str, t_line *line)
{
    int i;
    char **strsplit;

    i = 0;
    while (str[i])
    {
        if (str[i] == ',')
        {
            strsplit = ft_split(str, ',');
            line->coeffdir = ft_atoi(strsplit[0]);
            line->color = ft_hex_to_int(strsplit[1]);
            ft_free_entrystr(strsplit);
            return (line);
        }
        i++;
    }
    line->coeffdir = ft_atoi(str);
    line->color = WHITECOLOR;
    return (line);
}

t_list *ft_fill_struct(t_list *list, t_input input, int fd)
{
    int i;
    int j;
    char **str;
    t_line *line;

    (void)fd;
    j = 1;
    str = ft_input_str_space(); // je lis une ligne en separant par les espaces
    printf("str[i] %s\n", str[0]);
    line = ft_init_tline();
    while (str != NULL)
    {
        i = 0;
        while (str[i] != NULL)
        { // je lis chaque case et je regarde si il ya une couleur en plus du coef directeur
            line = ft_input_str_coma(str[i], line);
            if (j == 1)
            {
                list->ptrbegin = line;
            }
            line->index = j;
            ft_search_top(list, input, line);
            ft_search_behind(list, input, line);
            line->next = ft_init_tline();
            line = line->next;
            i++;
            j++;
        }
        ft_free_entrystr(str);
        str = ft_input_str_space();
    }
    ft_search_x1y1(list, input);
    ft_read_tline(list);
    return (list);
}
