/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:03:26 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/22 14:56:51 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

int	ft_printf(const char *entry, ...)
{
	va_list	parameter;
	int		lengthoutput;

	va_start(parameter, entry);
	lengthoutput = 0;
	while (*entry)
	{
		if (*entry == '%')
		{
			lengthoutput = ft_chooseprint(lengthoutput, parameter, entry);
			entry++;
		}
		else
		{
			ft_putchar_fd(*entry, 1);
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
	char *ptr = NULL;
	// char *str = NULL;

	ptr = malloc(sizeof(char) * 2147483661);

	unsigned int i = 0;
	while(i < 2147483661)
	{
		ptr[i] = 'q';
		i++;
	}

	printf("%d\n", ft_printf("%s\n",ptr));
	printf("%d\n", printf("%s\n",ptr));


	// printf("%d\n", ft_printf("%x-%%-%c-%d-%s-%p-%s", 2147483647, '/', 38,
	// 		"salut",ptr,str));
	// printf("%d\n", printf("%x-%%-%c-%d-%s-%p-%s", 2147483647, '/', 38,
	// 		"salut",ptr,str));
}