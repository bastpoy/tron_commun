/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 20:55:36 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/23 16:01:27 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putuint_fd(unsigned int n, int fd, int *error, int *i)
{
	if (n > 9)
	{
		ft_putuint_fd(n / 10, fd, error, i);
	}
	*i = *i + 1;
	if(*error && ft_putchar(n % 10 + '0', fd) < 0)
		*error = 0;
}
