/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:59:34 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/20 15:37:13 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	ft_puthex_fd(unsigned long n, int fd, int lowerupper)
{
	unsigned long	absolut;
    char *hexastring;
	if(!lowerupper)
   		hexastring = "0123456789abcdef";
	if(lowerupper)
		hexastring = "0123456789ABCDEF";
	absolut = n;
	if (absolut > 15)
	{
		ft_puthex_fd(absolut / 16, fd, lowerupper);
	}
	ft_putchar_fd(hexastring[absolut % 16], fd);
}