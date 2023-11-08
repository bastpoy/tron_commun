/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:17:55 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/08 17:49:31 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	void	*ptr;

	ptr = malloc(elementCount * elementSize);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, elementCount);
	return (ptr);
}

// int main()
// {
//     int size = 5;
//     int octet = 4;
//     int i = 0;
//     char *str = (char *)ft_calloc(size, octet);
//     while (i < size)
//     {
//         printf("%d-", str[i]);
//         i++;
//     }
//     i = 0;
//     printf("\n");
//     str = (char *)calloc(size, octet);
//     while (i < size)
//     {
//         printf("%d-", str[i]);
//         i++;
//     }
//     printf("\n%p", ft_calloc(size, octet));
// }