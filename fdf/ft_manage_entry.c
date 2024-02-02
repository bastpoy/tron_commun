/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_entry.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:34:50 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/02 19:08:58 by bpoyet           ###   ########.fr       */
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
        if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\n') &&
             str[i] != '\n')
        {
            j++;
        }
        i++;
    }
    return (j);
}

t_input ft_get_length_width(char *entry)
{
    int fd;
    char *str;
    t_input input;

    fd = open(entry, O_RDONLY);
    str = get_next_line(fd);
    input.abs = ft_strlen_space_backn(str);
    input.total = input.abs;
    input.ord = 0;
    while (str)
    {
        input.ord++;
        free(str);
        str = get_next_line(fd);
        input.total += ft_strlen_space_backn(str);
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

char **ft_input_str_space(char *entry)
{
    char *strentry;
    char **strsplit;
    static int fd = 0;

    if (fd == 0)
        fd = open(entry, O_RDONLY);
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
            line->z1 = 3 * ft_atoi(strsplit[0]);
            line->color = ft_hex_to_int(strsplit[1]);
            ft_free_entrystr(strsplit);
            return (line);
        }
        i++;
    }
    line->z1 = 3 * ft_atoi(str);
    // printf("line z1 %f\n",line->z1);
    line->color = WHITECOLOR;
    return (line);
}

t_list *ft_fill_struct(t_list *list, t_input input, char *entry)
{ 
    int i;
    int j;
    char **str;
    t_line *line;

    j = 1;
    str = ft_input_str_space(entry); // je lis une ligne en separant par les espaces
    line = ft_init_tline();
    list->ptrbegin = line;
    while (str != NULL)
    {
        i = 0;
        while (str[i] != NULL)
        { // je lis chaque case et je regarde si il ya une couleur en plus du coef directeur
            line = ft_input_str_coma(str[i], line);
            line->index = j;
            ft_search_behind(list, input, line);
            ft_search_top(list, input, line);
            ft_indicexyz(list, line, input, j);
            if (j < input.total)
                line->next = ft_init_tline(); // apres les fonctions sinon je demarre a lindice -1
            line = line->next;
            i++;
            j++;
        }
        ft_free_entrystr(str);
        str = ft_input_str_space(entry);
    }
    return (list);
}
