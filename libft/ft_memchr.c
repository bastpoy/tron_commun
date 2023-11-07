/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:24:47 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/07 17:45:41 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void *memchr(const void *memoryBlock, int searchedChar, size_t size)
{
    char *ptr;
    ptr = (char *)memoryBlock;
    printf("ptr[1] %d\n", ptr[0]);
    while (size-- > 0)
    {
        printf("ptr %c et searchedchar %d\n", *ptr, searchedChar);
        if (*ptr == (char)searchedChar)
            return ((void *)memoryBlock);
        ptr++;
    }
    return (0);
}
int main()
{
    char data[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    const unsigned int size = 10;

    // On recherche une valeur inhéxistante :
    void *found = memchr(data, 500, size);
    if (found == NULL)
        printf("aucune correspondance\n");
    else
        printf("une correspondqnce");
}