/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:07:40 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/11 05:42:19 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	unsigned int	j;
	size_t			i;

	j = 0;
	i = 0;
	while (src[j])
		j++;
	if (size == 0)
		return (j);
	while (i < size - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (j);
}

// #include <stdio.h>
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
