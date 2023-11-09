/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:31:21 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/09 17:03:26 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_trym_start(char const *s1, char const *set)
{
    int i;

    i = 0;
    while(s1[i])
    {
        if(ft_strchr(set, s1[i]) == 0)
            break;
        i++;
    }
    return (i);
}

int ft_trym_end(char const *s1, char const *set)
{
    int i;

    i = ft_strlen((char*)s1) - 1;
    while(i > 0)
    {
        if(ft_strchr(set, s1[i]) == 0)
            break; 
        i--; 
    }
    return (i);
}

char *ft_strtrim(char const *s1, char const *set)
{
    int indice_start;
    int indice_end;
    char *str;

    indice_start = ft_trym_start(s1, set);
    indice_end = ft_trym_end(s1,  set);
    if(indice_start > indice_end)
        return (ft_strdup(""));
    str = (char*)malloc((indice_end - indice_start + 1) * sizeof(char));
    if(!str)
        return (0);
    str = ft_substr(s1, indice_start, indice_end - indice_start + 1);
    return (str);
}

// #include <stdio.h>

// int main(void)
// {
//     printf("-%s-",ft_strtrim("sasaut", "setaapru"));
// }