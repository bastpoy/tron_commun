/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:31:19 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/06 23:16:51 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// void *ft_memset(void *s, int c, size_t n)
// {
//     char *dest
//     while(n > 0)
//     {
        
//     }
//     return s;
// }
void *ft_memset (void *dest, int val, size_t len)
{
  unsigned char *ptr = dest;
  while (len > 0)
  {
    *ptr = val;
    ptr++;
    len--;
  }
  return dest;
}
int main() {

    int array [] = { 54, 85, 20, 63, 21 };
    size_t size = sizeof( int ) * 5;
    int length;

    /* Display the initial values */
    for( length=0; length<5; length++) {
        printf( "%d ", array[ length ] );
    }
    printf( "\n" );

    /* Reset the memory bloc */
    printf("%p\n",ft_memset( array, 0, size ));
    // printf("%p\n",memset( array, 0, size ));
    printf("%p\n", &array[0]);

    /* Display the new values */
    for( length=0; length<5; length++) {
        printf( "%d ", array[ length ] );
    }
    printf( "\n" );
    
    return 0;
}