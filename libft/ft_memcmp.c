/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:08:46 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/08 17:50:09 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

int ft_memcmp(const void *ptr1, const void *ptr2, size_t size)
{
	char *cpptr1;
	char *cpptr2;

	cpptr1 = (char *)ptr1;
	cpptr2 = (char *)ptr2;
	while (size-- > 0 && *cpptr1 == *cpptr2)
	{
		cpptr1++;
		cpptr2++;
	}
	return (*cpptr1 - *cpptr2);
}
// int main(void)
// {
//     int array1 [] = { 54, 85, 20, 63, 21 };
//     int array2 [] = { 54, 85, 20, 63, 20 };
//     size_t size = sizeof( int ) * 5;
//     printf("%d\n",ft_memcmp(array1,array2,size));
//     printf("%d\n",memcmp(array1,array2,size));
//     return (0);
// }