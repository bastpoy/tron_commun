/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:07:40 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/08 17:52:09 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcpy(char *dest, char *src, size_t size)
{
	unsigned int j;
	unsigned int i;

	j = 0;
	i = 0;
	//	if (src[0] == '\0' || size <= 0)
	//	{
	//		return (0);
	//	}
	while (src[j] != '\0')
	{
		j++;
	}
	while (i < size - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	if (i == size - 1 || src[i])
	{
		dest[i] = '\0';
		dest++;
	}
	return (j);
}

// int	main(void)
// {
// 	char source[] = "qwerqwrfwfqwef";
// 	char destination[] = "wqwrqwrqwr";
// 	unsigned int j = 0;
// 	int i=0;
// 	j = ft_strlcpy(destination, source, 15);
// 	printf("%u\n", j);

// 	while (destination[i])
// 	{
// 		printf("%c", destination[i]);
// 		i++;
// 	}
// }
