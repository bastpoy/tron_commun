/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:05:34 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/20 17:07:50 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

void	ft_puthex_fd(unsigned long n, int fd, int lowerupper);
void	ft_putuint_fd(unsigned int n, int fd);
size_t ft_dividhex(unsigned long n);

#endif