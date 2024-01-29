/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printcara.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:30:00 by bpoyet            #+#    #+#             */
/*   Updated: 2023/12/04 13:38:51 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printcara(char c, int fd, ssize_t lengthoutput)
{
	ssize_t	lengthbuf;

	lengthbuf = 0;
	lengthbuf = write(fd, &c, 1);
	if (lengthbuf < 0)
		return (-1);
	lengthoutput += lengthbuf;
	return (lengthoutput);
}
