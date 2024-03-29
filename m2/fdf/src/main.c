/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:19:58 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/23 11:42:34 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

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
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\n' || str[i
					+ 1] == '\0') && str[i] != '\n')
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
	int		temp;
	char	*str;
	t_input	input;

	fd = open(entry, O_RDONLY);
	if (fd < 0 || !(error_openfile(entry)) || check_map(entry))
		ft_return_error("cannot open file\n");
	str = get_next_line(fd);
	input.abs = ft_strlen_space_backn(str);
	input.ord = 0;
	while (str)
	{
		input.ord++;
		temp = ft_strlen_space_backn(str);
		if (temp != input.abs)
			error_size_line(fd, "line not correct", str);
		free(str);
		str = get_next_line(fd);
	}
	if (input.abs * input.ord > 300000)
		ft_return_error("Map too big");
	close(fd);
	return (input);
}

int	main(int argc, char **argv)
{
	t_input	input;
	t_map	***map;
	t_data	*data;

	if (argc == 2)
	{
		input = ft_get_length_width(argv[1]);
		map = ft_fill_struct(input, argv[1]);
		data = init_data(map, input);
		autofocus(map, input, data);
		mlx_hook(data->mlx_win, 17, 0, close_window, (void *)data);
		mlx_hook(data->mlx_win, KeyPress, KeyPressMask, key_hook, (void *)data);
		mlx_loop(data->mlx_ptr);
	}
	else
		ft_return_error("Argument not good\n");
	return (0);
}
