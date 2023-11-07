/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:07:51 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/07 13:45:42 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>
#include <string.h>

void *ft_memcpy(void *dest, const void *src, size_t size)
{
    char *ptrdest;
    const char *ptrsrc;

    ptrdest = dest;
    ptrsrc = src;
    while (size-- > 0)
        *ptrdest++ = *ptrsrc++;
    return (ptrdest);
}

// int main()
// {

//     int array[] = {54, 85, 20, 63, 21};
//     int *copy = NULL;
//     int length = sizeof(int) * 5;

//     /* Memory allocation and copy */
//     copy = (int *)malloc(length);
//     ft_memcpy(copy, array, length);

//     /* Display the copied values */
//     for (length = 0; length < 5; length++)
//     {
//         printf("%d ", copy[length]);
//     }
//     printf("\n");

//     free(copy);

//     return 0;
// }