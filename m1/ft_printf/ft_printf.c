/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:03:26 by bpoyet            #+#    #+#             */
/*   Updated: 2023/12/04 14:58:10 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *entry, ...)
{
	va_list	parameter;
	ssize_t	lengthoutput;

	va_start(parameter, entry);
	lengthoutput = 0;
	if (!entry || write(1, 0, 0) == -1)
		return (-1);
	while (*entry)
	{
		if (*entry == '%')
		{
			lengthoutput = ft_chooseprint(lengthoutput, parameter, entry);
			entry++;
		}
		else
			lengthoutput = ft_printcara(*entry, 1, lengthoutput);
		if (lengthoutput < 0)
			return (-1);
		entry++;
	}
	va_end(parameter);
	return (lengthoutput);
}
