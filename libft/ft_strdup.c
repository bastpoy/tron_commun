/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:48:08 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/08 18:03:06 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include <string.h>

// int ft_strlen(char *str)
// {
//     int i;

//     i = 0;
//     while (str[i])
//         i++;
//     return (i);
// }

char *ft_strdup(const char *src)
{
    int i;
    char *dest;

    i = ft_strlen((char *)src);
    dest = (char *)malloc((i + 1) * sizeof(char));
    i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
int main(void)
{
    printf("%s\n", ft_strdup("salut"));
    printf("%s\n", strdup("salut"));
}