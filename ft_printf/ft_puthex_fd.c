/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:59:34 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/23 16:11:42 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	ft_puthex_fd(unsigned long n, int fd, int lowerupper, int *error, int *i)
{
	unsigned long	absolut;
	char			*hexastring;

	if (!lowerupper)
		hexastring = "0123456789abcdef";
	if (lowerupper)
		hexastring = "0123456789ABCDEF";
	absolut = n;
	if (absolut > 15)
	{
		ft_puthex_fd(absolut / 16, fd, lowerupper, error, i);
	}
	*i = *i + 1;
	if(*error && ft_putchar(hexastring[absolut % 16], fd) == -1)
		*error = 0;
}
