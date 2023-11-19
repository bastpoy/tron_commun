/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:59:34 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/19 16:08:03 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static void	writenbr(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	absolut;
    char *hexastring;

    hexastring = "0123456789abcdef";
	if (n < 0)
	{
		absolut = -n;
		writenbr('-', fd);
	}
	else
		absolut = n;
	if (absolut > 15)
	{
		ft_putnbr_fd(absolut / 16, fd);
	}
	writenbr(hexastring[absolut], fd);
}