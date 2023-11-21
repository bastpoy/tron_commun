/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:03:26 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/21 15:55:18 by bpoyet           ###   ########.fr       */
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

// int	main(void)
// {
// 	char *ptr;
// 	ptr = malloc(sizeof(char));
// 	printf("%d\n", ft_printf("%x-%%-%c-%d-%s-%p-", 2147483647, '/', 38,
// 			"salut",ptr));
// // 	printf("%d\n", printf("%x-%%-%c-%d-%s-%p-", 2147483647, '/', 38,
// 			"salut",ptr));
// }