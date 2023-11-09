/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:56:23 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/09 14:05:56 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *str, const char *to_find, size_t len)
{
    char *cpstr;
    int i;
    int j;

    i = 0;
    j = 0;
    cpstr = (char *)str;
    while (cpstr[j] != '\0' && j < (int)len)
    {
        while (cpstr[j + i] == to_find[i] && i + j < (int)len)
        {
            i++;
        }
        if (to_find[i] == '\0')
        {
            return (cpstr + j);
        }
        i = 0;
        j++;
        len--;
    }
    return ((void *)0);
}

char *strnstr(const char *s, const char *find, size_t slen)
{
    char c, sc;
    size_t len;

    if ((c = *find++) != '\0')
    {
        len = strlen(find);
        do
        {
            do
            {
                if (slen-- < 1 || (sc = *s++) == '\0')
                    return (NULL);
            } while (sc != c);
            if (len > slen)
                return (NULL);
        } while (strncmp(s, find, len) != 0);
        s--;
    }
    return ((char *)s);
}

// #include <stdio.h>

// int main(void)
// {
//     char *str = "yo le rap";
//     char *to_find = "le";
//     size_t size = 2;
//     // printf("%s\n", catin());
//     printf("%s", ft_strnstr(str, to_find, size));
// }
