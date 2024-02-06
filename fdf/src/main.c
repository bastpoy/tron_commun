/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:19:58 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/06 18:59:49 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static size_t	ft_strlen_space_backn(const char *str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\n')
			&& str[i] != '\n')
		{
			j++;
		}
		i++;
	}
	return (j);
}

static t_input	ft_get_length_width(char *entry)
{
	int		fd;
	char	*str;
	t_input	input;

	fd = open(entry, O_RDONLY);
	str = get_next_line(fd);
	input.abs = ft_strlen_space_backn(str);
	input.total = input.abs;
	input.ord = 0;
	while (str)
	{
		input.ord++;
		free(str);
		str = get_next_line(fd);
		input.total += ft_strlen_space_backn(str);
	}
	close(fd);
	return (input);
}

int	main(int argc, char **argv)
{
	t_input	input;
	t_list	*list;
	t_data *img;

	if (argc == 2)
	{
		input = ft_get_length_width(argv[1]);
		if (!input.total)
			return (0);
		list = ft_init_pointbegin(input);
		if (!list || !img)
			close_window(list);
		ft_fill_struct(list, input, argv[1]);
		if (!list->err)
			close_window(list);
		color_to_point(list);
		ft_line_xyprojtop1(list, list->data, img);
		mlx_put_image_to_window(list->data->mlx_ptr, list->data->mlx_win, img->img, 0, 0);
		mlx_hook(list->data->mlx_win, 17, 0, close_window, (void *)list);
		mlx_hook(list->data->mlx_win, KeyPress, KeyPressMask, key_hook,
			(void *)list);
		if (!list->err)
			close_window(list);
		mlx_loop(list->data->mlx_ptr);
	}
	return (0);
}
