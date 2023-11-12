/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:03:04 by bpoyet            #+#    #+#             */
/*   Updated: 2023/11/11 06:28:47 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
	{
		return (c);
	}
	return (0);
}

/*
int	main(void)
{
	char source[] = "gwegw*(&*(";
	int res = 0;
	res = ft_str_is_alpha(source);
	printf("%d", res);
}*/