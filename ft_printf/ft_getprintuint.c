/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getprintuint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:08:16 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/24 11:17:20 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	ft_putuint_fd(unsigned int n, int fd, int *error, ssize_t *i)
{
	if (n > 9)
	{
		ft_putuint_fd(n / 10, fd, error, i);
	}
	*i = *i + 1;
	if (*error && ft_putchar(n % 10 + '0', fd) < 0)
		*error = 0;
}

ssize_t	ft_getprintuint(va_list parameter)
{
	unsigned int	value;
	ssize_t			length;
	int				error;

	error = 1;
	length = 0;
	value = va_arg(parameter, unsigned int);
	ft_putuint_fd(value, 1, &error, &length);
	if (!error)
		return (-1);
	return (length);
}
