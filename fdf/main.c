/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:19:58 by bpoyet            #+#    #+#             */
/*   Updated: 2024/01/06 20:41:43 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

void ft_losange(void *mlx_ptr, void *mlx_win, t_data img)
{
    int x = 80;
    int y = 80;
    int i = 0;

    while (i < 20)
    {
        ft_mlx_pixel_put(&img, x, y, 0x00ff0000);
        mlx_put_image_to_window(mlx_ptr, mlx_win, img.img, 0, 0);
        x++;
        y--;
        i++;
    }
    while (i < 40)
    {
        ft_mlx_pixel_put(&img, x, y, 0x00ff0000);
        mlx_put_image_to_window(mlx_ptr, mlx_win, img.img, 0, 0);
        x++;
        y++;
        i++;
    }
    while (i < 60)
    {
        ft_mlx_pixel_put(&img, x, y, 0x00ff0000);
        mlx_put_image_to_window(mlx_ptr, mlx_win, img.img, 0, 0);
        x--;
        y++;
        i++;
    }
    while (i < 80)
    {
        ft_mlx_pixel_put(&img, x, y, 0x00ff0000);
        mlx_put_image_to_window(mlx_ptr, mlx_win, img.img, 0, 0);
        x--;
        y--;
        i++;
    }
}

void ft_circle(void *mlx_ptr, void *mlx_win, t_data img)
{
    // int a = 60;
    // int b = 60;
    double x = 1;
    double y = 0;
    double z = 0;
    // int r = 50;
    int i = 0;

    while (i < 300)
    {
        z = 2500 - (pow(x, 2) - 120 * x + 3600);
        if (z >= 0)
        {
            y = sqrt(z) + 60;
            ft_mlx_pixel_put(&img, x, y, 0x00ff0000);
            mlx_put_image_to_window(mlx_ptr, mlx_win, img.img, 0, 0);
        }
        printf("x %f y %f\n", x, y);
        x++;
        i++;
    }
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

int main(void)
{
    void *mlx_ptr;
    void *mlx_win;
    int fd;
    char *str;
    t_data img;

    mlx_ptr = mlx_init();
    mlx_win = mlx_new_window(mlx_ptr, 1920, 1080, "Hello world");
    img.img = mlx_new_image(mlx_ptr, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

    fd = open("entry.fdf", O_RDONLY);
    str = get_next_line(fd);

    ft_mlx_pixel_put(&img, 1910, 1000, 0x00ff0000);
    mlx_put_image_to_window(mlx_ptr, mlx_win, img.img, 0, 0);

    mlx_loop(mlx_ptr);
}
