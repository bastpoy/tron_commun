/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:06:57 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/23 16:42:04 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	writenbr(char c, int fd)
{
	return (write(fd, &c, 1));
}

void	ft_putnbr(int n, int fd, int *error, int *i)
{
	unsigned int	absolut;

	if (n < 0)
	{
		*i = *i + 1;
		absolut = -n;
		writenbr('-', fd);
	}
	else
		absolut = n;
	if (absolut > 9)
		ft_putnbr(absolut / 10, fd, error, i);
	*i = *i + 1;
	if(*error && writenbr(absolut % 10 + '0', fd) < 0)
		*error = 0;
}