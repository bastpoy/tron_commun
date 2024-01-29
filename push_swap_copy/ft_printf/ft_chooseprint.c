/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chooseprint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:04:33 by bpoyet            #+#    #+#             */
/*   Updated: 2023/12/04 14:51:24 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_chooseprint(ssize_t lengthoutput, va_list parameter,
		const char *entry)
{
	ssize_t	lengthbuf;

	entry++;
	lengthbuf = 0;
	if (*entry == 'c' || *entry == 's')
		lengthbuf = ft_getprintchar(parameter, entry);
	else if (*entry == 'p' || *entry == 'x' || *entry == 'X')
		lengthbuf = ft_getprintaddr(parameter, entry);
	else if (*entry == 'd' || *entry == 'i')
		lengthbuf = ft_getprintint(parameter);
	else if (*entry == 'u')
		lengthbuf = ft_getprintuint(parameter);
	else if (*entry == '%')
		lengthbuf = ft_putchar('%', 1);
	else
	{
		lengthbuf = ft_putchar('%', 1);
		lengthbuf += ft_putchar(*entry, 1);
	}
	if (lengthbuf < 0)
		return (-1);
	lengthoutput += lengthbuf;
	return (lengthoutput);
}
