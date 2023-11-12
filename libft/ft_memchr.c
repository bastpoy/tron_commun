/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:24:47 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/10 17:20:11 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t size)
{
	char	*ptr;

	ptr = (char *)str;
	while (size > 0)
	{
		if (*ptr == c)
			return ((void *)str);
		ptr++;
		str++;
		size--;
	}
	return (0);
}

// #include <stdio.h>
// int main()
// {
//     char data[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
//     const unsigned int size = 10;

//     // On recherche une valeur inhéxistante :
//     void *found = memchr(data, 60, size);
//     if (found == NULL)
//         printf("aucune correspondance\n");
//     else
//         printf("une correspondqnce");
// }