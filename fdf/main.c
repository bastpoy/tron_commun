/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:19:58 by bpoyet            #+#    #+#             */
/*   Updated: 2024/02/04 23:57:16 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_free_entrystr(char **str)
{
    int i;

    i = 0;
    if (str)
    {
        while (str[i])
        {
            free(str[i]);
            i++;
        }
        free(str[i]);
        free(str);
    }
}

int main(int argc, char **argv)
{
    t_input input;
    t_list *list;

    if (argc == 2)
    {
        input = ft_get_length_width(argv[1]);
        list = ft_init_pointbegin();
        list = init_data(list, input);

        printf("input abs %d input ord %d et total %d\n", input.abs, input.ord, input.total);
        ft_fill_struct(list, input, argv[1]);
        color_to_point(list);
        ft_line_xyprojtop1(list, list->data);
        mlx_hook(list->data->mlx_win, 17, 0, mouse_hook, (void *)list);
        mlx_hook(list->data->mlx_win, KeyPress, KeyPressMask, key_hook, (void *)list);
        mlx_loop(list->data->mlx_ptr);
        ft_free_list(list);
    }
    return (0);
}
