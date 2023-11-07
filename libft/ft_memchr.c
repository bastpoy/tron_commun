/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:24:47 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/07 21:01:48 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

// #include <stdio.h>

void	*memchr(const void *str, int c, size_t size)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)str;
	while (size-- > 0)
	{
		if (*ptr == (unsigned char)c)
			return ((void *)str);
		ptr++;
	}
	return (0);
}
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