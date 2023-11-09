/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:18:17 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/09 23:47:48 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

// static size_t	get_digits(int n)
// {
// 	size_t	i;

// 	i = 1;
// 	while (n /= 10)
// 		i++;
// 	return (i);
// }

// char			*ft_itoa(int n)
// {
// 	char		*str_num;
// 	size_t		digits;
// 	long int	num;

// 	num = n;
// 	digits = get_digits(n);
// 	if (n < 0)
// 	{
// 		num *= -1;
// 		digits++;
// 	}
// 	if (!(str_num = (char *)malloc(sizeof(char) * (digits + 1))))
// 		return (NULL);
// 	*(str_num + digits) = 0;
// 	while (digits--)
// 	{
// 		*(str_num + digits) = num % 10 + '0';
// 		num = num / 10;
// 	}
// 	if (n < 0)
// 		*(str_num + 0) = '-';
// 	return (str_num);
// }

int countnum(int n)
{
    int i;

    i = 0;
    while(n > 10)
    {
        n /= 10;
        i++;
    }
    return (i);
}

char *ft_itoa(int n)
{
    int count;
    char *str = "salut";
    char *str1;
    count = countnum(n);
    str1 = (char*)malloc((count + 1) * sizeof(char));
    
    printf("count %d\n", count);
    return (str);
}

int main(void)
{
    printf("%s",ft_itoa(3535));
}