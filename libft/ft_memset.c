/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:31:19 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/09 13:10:03 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void *ft_memset(void *dest, int val, size_t len)
{
	char *ptr;

	ptr = dest;
	while (len-- > 0)
		*ptr++ = val;
	return (dest);
}
// int main()
// {

//   int array[] = {54, 85, 20, 63, 21};
//   size_t size = sizeof(int) * 5;
//   int length;

//   /* Display the initial values */
//   for (length = 0; length < 5; length++)
//   {
//     printf("%d ", array[length]);
//   }
//   printf("\n");

//   /* Reset the memory bloc */
//   ft_memset(array, 2, size);

//   /* Display the new values */
//   for (length = 0; length < 5; length++)
//   {
//     printf("%d ", array[length]);
//   }
//   printf("\n");

//   return (0);
// }