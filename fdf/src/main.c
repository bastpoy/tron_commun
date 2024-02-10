/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:19:58 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/10 18:22:50 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char *dst;

	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

static size_t ft_strlen_space_backn(const char *str)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\n') && str[i] != '\n')
		{
			j++;
		}
		i++;
	}
	return (j);
}

static t_input ft_get_length_width(char *entry)
{
	int fd;
	char *str;
	t_input input;

	fd = open(entry, O_RDONLY);
	if (fd < 0)
		ft_return_error("cannot open file");
	str = get_next_line(fd);
	input.abs = ft_strlen_space_backn(str);
	input.ord = 0;
	while (str)
	{
		input.ord++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (input);
}

int main(int argc, char **argv)
{
	t_input input;
	t_map ***map;
	t_mov *mov;

	(void)map;
	if (argc == 2)
	{
		mov = init_mov();
		input = ft_get_length_width(argv[1]);
		printf("input abs %d ord %d\n", input.abs, input.ord);
		map = ft_fill_struct(input, argv[1]);
		free_map(map);
		// color_to_point(list);
		// ft_line_xyprojtop1(list);
		// mlx_hook(list->data->mlx_win, 17, 0, close_window, (void *)list);
		// mlx_hook(list->data->mlx_win, KeyPress, KeyPressMask, key_hook,
		// 		 (void *)list);
		// mlx_loop(list->data->mlx_ptr);
	}
	return (0);
}
