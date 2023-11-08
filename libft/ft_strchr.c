/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:02:47 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/08 17:50:50 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strchr(const char *s, int c)
{
    char *str;

    str = (char *)s;
    while (*str != '\0')
    {
        if (*str == (char)c)
        {
            return (str);
        }
        str++;
    }
    return (0);
}

// int main(void)
// {
//     char *str = "y le y rap";
//     printf("%s", strchr(str, 'o'));
// }