/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:08:46 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/11 05:07:50 by bpoyet           ###   ########.fr       */
/*                                              ;							  */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t size)
{
	unsigned char	*cpptr1;
	unsigned char	*cpptr2;

	cpptr1 = (unsigned char *)ptr1;
	cpptr2 = (unsigned char *)ptr2;
	if (size == 0)
		return (0);
	while (size > 0)
	{
		if (*cpptr1 != *cpptr2)
			return (*cpptr1 - *cpptr2);
		cpptr1++;
		cpptr2++;
		size--;
	}
	return (0);
}

// int	ft_memcmp(const void *s1, const void *s2, size_t n)
// {
// 	const unsigned char	*ss1;
// 	const unsigned char	*ss2;
// 	size_t				i;

// 	i = 0;
// 	ss1 = (const unsigned char *)s1;
// 	ss2 = (const unsigned char *)s2;
// 	while (i < n)
// 	{
// 		if (ss1[i] != ss2[i])
// 			return (ss1[i] - ss2[i]);
// 		i++;
// 	}
// 	return (0);
// }
// #include <stdio.h>

// int main(void)
// {
// 	char *array1 = "salut";
// 	char *array2 = "salute";
//     size_t size = sizeof( int ) * 6;
//     printf("%d\n",ft_memcmp(array1,array2,size));
//     printf("%d\n",memcmp(array1,array2,size));
//     return (0);
// }