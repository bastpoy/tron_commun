/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getprintaddr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:55:11 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/23 18:03:02 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_getprintaddr(va_list parameter, const char *entry)
{
	unsigned int	adress;
	unsigned long long 	adresslong;
	int error;
	int i;

	i = 0;
	error = 1;
	adress = va_arg(parameter, unsigned int);
	adresslong = va_arg(parameter,unsigned long long);
	if (*entry == 'x')
		ft_puthex_fd(adress, 1, 0, &error, &i);
	else if (*entry == 'X')
		ft_puthex_fd(adress, 1, 1, &error, &i);
	else
	{
		if(!adresslong)
		{
			ft_putstr("(nil)", 1);
			return(5);
		}
		ft_putstr_fd("0x", 1);
		i += 2;
		ft_puthex_fd(adresslong, 1, 0, &error, &i);
	}
	if(!error)
		return(-1);
	return (i);
}
