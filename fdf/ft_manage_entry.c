/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_entry.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:34:50 by bpoyet            #+#    #+#             */
/*   Updated: 2024/01/13 15:00:09 by bpoyet           ###   ########.fr       */
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
    return(strsplit);
}

char **ft_input_str_space()
{
    int fd;
    char *strentry;

    fd = 0;
    char **strsplit;
    fd = open("entry.fdf", O_RDONLY);
    strentry = get_next_line(fd);
    strsplit = ft_split(strentry, ' ');
    strsplit = ft_entry_backn(strsplit);
    free(strentry);
    return (strsplit);
}

int ft_hextodc(char hex){
   int dec;

    dec = 0;
    if(hex >= '0' && hex <='9')
        dec = hex - '0';
    else
        dec = hex - 'A' + 10;
   return dec;
}

int ft_hex_to_int(char *str)
{
    int output;
    int i;
    int x;

    i = ft_strlen(str, 1) - 1;
    output = 0;
    while(i >= 2)
    {
        if(str[i] >= '0' && str[i] <='9')
            x = (str[i] - '0');
        else if (str[i] >= 'A' && str[i] <='F')
        {
            x = (str[i] - 'A' + 10);
            printf("x %d\n", x);
        }
        else
            x = (str[i] - 'a' + 10);
        output = output + x * pow(16, i);
        printf("i %d output %d et str[i] %c\n", i, output, str[i]);
        i--;
    }
    printf("int %d\n", output);
    return (output);
}

t_coeffcolor ft_parameter_point(char *str)
{
    int i;
    t_coeffcolor point;
    char **strsplit;

    i = 0;
    while(str[i])
    {
        if(str[i] == ',')
        {
            strsplit = ft_split(str, ',');
            printf("%s\n", strsplit[1]);
            point.coeffdir = ft_atoi(strsplit[0]);
            point.color = ft_hex_to_int(strsplit[1]);
            return(point);
        }
        i++;
    }
    point.coeffdir = ft_atoi(str);
    point. color = 0xffffff;
    return (point);
}
