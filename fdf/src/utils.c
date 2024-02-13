/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:18:02 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/13 14:19:38 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	ft_hex_to_int(char *str)
{
	int	output;
	int	i;
	int	x;

	i = 7;
	output = 0;
	while (i >= 2)
	{
		if (str[i] >= '0' && str[i] <= '9')
			x = (str[i] - '0');
		else if (str[i] >= 'A' && str[i] <= 'F')
			x = (str[i] - 'A' + 10);
		else
			x = (str[i] - 'a' + 10);
		output = output + x * pow(16, i - 2);
		i--;
	}
	return (output);
}

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel
					/ 8));
		*(unsigned int *)dst = color;
	}
}
