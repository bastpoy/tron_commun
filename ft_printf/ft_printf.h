/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:05:34 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/21 16:01:25 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int		ft_chooseprint(int lengthoutput, va_list parameter, const char *entry);
int		ft_getprintaddr(va_list parameter, const char *entry);
int		ft_getprintint(va_list parameter);
int		ft_getprintperc(void);
int		ft_getprintuint(va_list parameter);
int		ft_getprintchar(va_list parameter, const char *entry);
void	ft_puthex_fd(unsigned long n, int fd, int lowerupper);
void	ft_putuint_fd(unsigned int n, int fd);
size_t	ft_dividhex(unsigned long n);
int		ft_printf(const char *entry, ...);

#endif