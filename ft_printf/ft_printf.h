/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:05:34 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/23 16:39:47 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <limits.h>
# include <stdarg.h>

int		ft_chooseprint(int lengthoutput, va_list parameter, const char *entry);
int		ft_getprintaddr(va_list parameter, const char *entry);
int		ft_getprintint(va_list parameter);
int		ft_getprintuint(va_list parameter);
int		ft_getprintchar(va_list parameter, const char *entry);
int		ft_putchar(char c, int fd);
void	ft_putnbr(int n, int fd, int *error, int *i);
int		ft_putstr(char *s, int fd);
void	ft_puthex_fd(unsigned long n, int fd, int lowerupper, int *error, int *i);
void	ft_putuint_fd(unsigned int n, int fd, int *error, int *i);
size_t	ft_dividhex(unsigned long n);
int		ft_printf(const char *entry, ...);

#endif