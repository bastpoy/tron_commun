/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:02:47 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/09 14:54:01 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strchr(const char *s, int c)
{
    char *str;

    str = (char *)s;
    while (*str)
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