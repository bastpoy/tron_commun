/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:02:54 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/14 14:54:25 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	char		*ptrdest;
	const char	*ptrsrc;

	ptrdest = (char *)dest;
	ptrsrc = src;
	if (!dest && !src)
		return (0);
	if (ptrdest > ptrsrc)
	{
		while (size-- > 0)
			ptrdest[size] = ptrsrc[size];
	}
	else
	{
		while (size-- > 0)
			*ptrdest++ = *ptrsrc++;
	}
	return (dest);
}

// #include <stdio.h>
// #define ELEMENT_COUNT 10
// int main(void)
// {
// 	// char src[] = {54, 85, 20, 63, 21};
// 	char *src = (char *)0xffffffffe000;
// 	char *dest = (char *)0xfffffffff000;
// 	int length = sizeof(char) * 5;

// 	/* Memory allocation and dest */
// 	printf("src %p and dest %p\n", src, dest);
// 	dest = (char *)malloc(length);
// 	printf("la length vaut %d\n", length);
// 	ft_memmove(dest, src, length);

// 	/* Display the copied values */
// 	for (length = 0; length < 5; length++)
// 	{
// 		printf("%d ", dest[length]);
// 	}
// 	printf("\n");

// 	free(dest);

// 	return (0);
// }