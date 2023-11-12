/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:07:51 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/10 16:55:46 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	char		*ptrdest;
	const char	*ptrsrc;

	ptrdest = (char *)dest;
	ptrsrc = (char *)src;
	while (size > 0)
	{
		*ptrdest++ = *ptrsrc++;
		size--;
	}
	return (dest);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char *str = "zyxwvutsrqponmjjjjjjjjjjjjjjjj";
// 	char *copy = NULL;
// 	int length = sizeof(int) * 30;
// 	/* Memory allocation and copy */
// 	copy = (char *)malloc(length);
// 	ft_memcpy(copy, str, length);

// 	/* Display the copied values */
// 	for (length = 0; length < 31; length++)
// 	{
// 		printf("%c-", copy[length]);
// 	}
// 	printf("\n");

// 	free(copy);

// 	return (0);
// }