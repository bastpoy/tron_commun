/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 20:55:36 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/19 20:56:35 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	writenbr(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(unsigned int n, int fd)
{
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	writenbr(n % 10 + '0', fd);
}