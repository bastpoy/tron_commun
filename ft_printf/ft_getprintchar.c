/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getprintchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:56:33 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/24 11:15:46 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

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
			ft_putstr("(null)", 1);
			return (6);
		}
		if (ft_strlen(str) > INT_MAX || ft_putstr(str, 1) < 0)
			return (-1);
		return (ft_strlen(str));
	}
}
