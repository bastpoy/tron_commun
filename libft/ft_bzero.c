/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:32:34 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/07 09:34:28 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
void ft_bzero(void *s, size_t n)
{
    char *ptr;

    ptr = s;
    while(n-- > 0)
        *ptr++ = 0;
}
// int main() {

//     int array [] = { 54, 85, 20, 63, 21 };
//     size_t size = sizeof( int ) * 5;
//     int length;

//     /* Display the initial values */
//     for( length=0; length<5; length++) {
//         printf( "%d ", array[ length ] );
//     }
//     printf( "\n" );

//     /* Reset the memory bloc */
//     ft_bzero(array, size);
//     // printf("%p\n",ft_bzero( array, size ));
//     // printf("%p\n",memset( array, 0, size ));
//     printf("%p\n", &array[0]);

//     /* Display the new values */
//     for( length=0; length<5; length++) {
//         printf( "%d ", array[ length ] );
//     }
//     printf( "\n" );
    
//     return 0;
// }