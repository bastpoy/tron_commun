/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getprintaddr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:55:11 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/24 12:10:37 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_p(unsigned long long n, int fd, int *error, ssize_t *i)
{
	char	*hexastring;

	hexastring = "0123456789abcdef";
	if (n > 15)
	{
		ft_puthex_p(n / 16, fd, error, i);
	}
	*i = *i + 1;
	if (*error && ft_putchar(hexastring[n % 16], fd) == -1)
		*error = 0;
}

void	ft_puthex_x(unsigned int n, int fd, int *error, ssize_t *i)
{
	char	*hexastring;

	hexastring = "0123456789abcdef";
	if (n > 15)
	{
		ft_puthex_x(n / 16, fd, error, i);
	}
	*i = *i + 1;
	if (*error && ft_putchar(hexastring[n % 16], fd) == -1)
		*error = 0;
}

void	ft_puthex_xmaj(unsigned int n, int fd, int *error, ssize_t *i)
{
	char	*hexastring;

	hexastring = "0123456789ABCDEF";
	if (n > 15)
	{
		ft_puthex_xmaj(n / 16, fd, error, i);
	}
	*i = *i + 1;
	if (*error && ft_putchar(hexastring[n % 16], fd) == -1)
		*error = 0;
}

ssize_t	ft_getprintaddr(va_list parameter, const char *entry)
{
	unsigned long long	adress;
	int					error;
	ssize_t				i;

	i = 0;
	error = 1;
	adress = va_arg(parameter, unsigned long long);
	if (*entry == 'x')
		ft_puthex_x(adress, 1, &error, &i);
	else if (*entry == 'X')
		ft_puthex_xmaj(adress, 1, &error, &i);
	else
	{
		if (!adress)
		{
			ft_putstr("(nil)", 1);
			return (5);
		}
		ft_putstr("0x", 1);
		i += 2;
		ft_puthex_p(adress, 1, &error, &i);
	}
	if (!error)
		return (-1);
	return (i);
}
