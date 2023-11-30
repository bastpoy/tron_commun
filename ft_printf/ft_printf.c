/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:03:26 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/28 15:47:46 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *entry, ...)
{
	va_list	parameter;
	ssize_t	lengthoutput;

	va_start(parameter, entry);
	lengthoutput = 0;
	while (*entry)
	{
		if (*entry == '%')
		{
			lengthoutput = ft_chooseprint(lengthoutput, parameter, entry);
			if (lengthoutput < 0)
				return (-1);
			entry++;
		}
		else
		{
			if (ft_putchar(*entry, 1) < 0)
				return (-1);
			lengthoutput++;
		}
		entry++;
	}
	va_end(parameter);
	return (lengthoutput);
}
