/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getprintchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:56:33 by bpoyet            #+#    #+#             */
/*   Updated: 2023/12/04 17:55:35 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_getprintchar(va_list parameter, const char *entry)
{
	char	caracter;
	char	*str;

	if (*entry == 'c')
	{
		caracter = (char)va_arg(parameter, int);
		if (ft_putchar(caracter, 1) < 0)
			return (-1);
		return (1);
	}
	else
	{
		str = va_arg(parameter, char *);
		if (!str)
		{
			if (ft_putstr("(null)", 1) < 0)
				return (-1);
			return (6);
		}
		if (ft_strlen(str) > INT_MAX || ft_putstr(str, 1) < 0)
			return (-1);
		return (ft_strlen(str));
	}
}
