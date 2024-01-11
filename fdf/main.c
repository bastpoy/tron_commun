/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:19:58 by bpoyet            #+#    #+#             */
/*   Updated: 2024/01/11 01:31:44 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

size_t ft_strlen_space_backn(const char *str)
{
    size_t i;
    size_t j;

    i = 0;
    j = 0;
    if (!str)
        return (0);
    while (str[i] != '\0')
    {
        if (str[i] != ' ' && str[i] != '\n')
        {
            printf("%c \n", str[i]);
            j++;
        }
        i++;
    }
    return (j);
}

t_input ft_get_length_width()
{
    int fd;
    char *str;
    t_input input;

    fd = open("entry.fdf", O_RDONLY);
    str = get_next_line(fd);
    input.abs = ft_strlen_space_backn(str);
    input.ord = 0;
    while (str)
    {
        input.ord++;
        str = get_next_line(fd);
    }
    printf("lengthstr %d et widthstr %d \n", input.abs, input.ord);
    close(fd);
    return (input);
}

int ft_get_abs(char *str)
{
    int count;

    count = 0;
    while (str)
    {
        if (*str == ' ')
            count++;
        str++;
    }
    count++;
    return (count);
}

void ft_line(void *mlx_ptr, void *mlx_win, t_data img, t_line point)
{
    double coef = (point.yb - point.ya) / (point.xb - point.xa);
    double yzero = point.ya - (coef * point.xa);
    int x;
    int y;
    int incr;

    incr = 1;
    while (point.xa != point.xb)
    {
        x = point.xa;
        y = (point.xa * coef) + yzero;
        ft_mlx_pixel_put(&img, x, y, 0x00ff0000);
        mlx_put_image_to_window(mlx_ptr, mlx_win, img.img, 0, 0);
        if (coef > 0)
            point.xa = point.xa + incr;
        else
            point.xa = point.xa - incr;
    }
}

int main(void)
{
    void *mlx_ptr;
    void *mlx_win;
    t_input input;

    t_line line1 = ft_create_tline(800, 1600, 100, 600);     // segment haut long
    t_line line2 = ft_create_tline(380, 1180, 467.5, 967.5); // segment bas long
    t_line line3 = ft_create_tline(800, 380, 100, 467.5);    // segment gauche larg
    t_line line4 = ft_create_tline(1600, 1180, 600, 967.5);  // segment droite larg

    printf("longueur %f et longueur %f", ft_line_length(line1), ft_line_length(line3));
    t_data img;

    mlx_ptr = mlx_init();
    mlx_win = mlx_new_window(mlx_ptr, 1920, 1080, "Hello world");
    img.img = mlx_new_image(mlx_ptr, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

    input = ft_get_length_width();

    printf("%d et %d\n", input.abs, input.ord);

    ft_line(mlx_ptr, mlx_win, img, line1);
    ft_line(mlx_ptr, mlx_win, img, line2);
    ft_line(mlx_ptr, mlx_win, img, line3);
    ft_line(mlx_ptr, mlx_win, img, line4);
    ft_line(mlx_ptr, mlx_win, img, ft_create_line(line3, ft_line_length(line3) / input.ord, line1, ft_line_length(line1)));

    mlx_loop(mlx_ptr);
}
