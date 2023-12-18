/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:05:34 by bpoyet            #+#    #+#             */
/*   Updated: 2023/12/04 13:35:37 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <limits.h>
# include <stdarg.h>

ssize_t	ft_chooseprint(ssize_t lengthoutput, va_list parameter,
			const char *entry);
ssize_t	ft_getprintaddr(va_list parameter, const char *entry);
ssize_t	ft_getprintint(va_list parameter);
ssize_t	ft_getprintuint(va_list parameter);
ssize_t	ft_getprintchar(va_list parameter, const char *entry);
int		ft_putchar(char c, int fd);
void	ft_putnbr(int n, int fd, int *error, ssize_t *i);
int		ft_putstr(char *s, int fd);
ssize_t	ft_dividhex(unsigned long n);
int		ft_printf(const char *entry, ...);
int		ft_printcara(char c, int fd, ssize_t lengthoutput);

#endif