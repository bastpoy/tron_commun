/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:48:08 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/09 14:05:03 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
// #include <stdio.h>

// int main(void)
// {
//     printf("%s\n", ft_strdup("salut"));
//     printf("%s\n", strdup("salut"));
// }