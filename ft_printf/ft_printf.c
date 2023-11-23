/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:03:26 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/23 17:20:39 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *entry, ...)
{
	va_list	parameter;
	ssize_t		lengthoutput;

	va_start(parameter, entry);
	lengthoutput = 0;
	while (*entry)
	{
		if (*entry == '%')
		{
			lengthoutput = ft_chooseprint(lengthoutput, parameter, entry);
			if(lengthoutput < 0)
				return (-1);
			entry++;
		}
		else
		{
			if(ft_putchar(*entry, 1) < 0)
				return(-1);
			lengthoutput++;
		}
		entry++;
	}
	va_end(parameter);
	return (lengthoutput);
}

#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_printf("%u\n", 42));
	printf("%d\n", printf("%u\n", 42));
	printf("%d\n", ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0));
	printf("%d\n", printf("   %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0));
}