/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:19:58 by bpoyet            #+#    #+#             */
/*   Updated: 2024/01/08 23:26:55 by bpoyet           ###   ########.fr       */
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

int *ft_get_length_width()
{
    int fd;
    char *str;
    int *lengthxy = malloc(sizeof(int) * 2);

    fd = open("entry.fdf", O_RDONLY);
    str = get_next_line(fd);
    lengthxy[0] = ft_strlen_space_backn(str);
    lengthxy[1] = 0;
    while (str)
    {
        lengthxy[1]++;
        str = get_next_line(fd);
    }
    printf("lengthstr %d et widthstr %d \n", lengthxy[0], lengthxy[1]);
    close(fd);
    return (lengthxy);
}

// void ft_grid(void *mlx_ptr, void *mlx_win, t_data img)
// {
// }
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

void ft_line(void *mlx_ptr, void *mlx_win, t_data img, double *value)
{
    double coef = (value[3] - value[2]) / (value[1] - value[0]);
    double yzero = value[2] - (coef * value[0]);
    printf("yzero %f\n", yzero);
    int x;
    int y;
    int incr;

    incr = 1;
    while (value[0] <= value[1])
    {
        x = value[0];
        y = (value[0] * coef) + yzero;
        ft_mlx_pixel_put(&img, x, y, 0x00ff0000);
        mlx_put_image_to_window(mlx_ptr, mlx_win, img.img, 0, 0);
        value[0] = value[0] + incr;
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
    double tab[4] = {1200, 1750, 50, 600};
    double tab1[4] = {150, 1250, 350, 850};
    int lengthx;
    int lengthy;
    int *lengthxy = malloc(sizeof(int) * 2);
    t_data img;

    mlx_ptr = mlx_init();
    mlx_win = mlx_new_window(mlx_ptr, 1920, 1080, "Hello world");
    img.img = mlx_new_image(mlx_ptr, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

    lengthxy = ft_get_length_width();
    lengthx = lengthxy[0];
    lengthy = lengthxy[1];
    printf("%d et %d\n", lengthx, lengthy);

    ft_line(mlx_ptr, mlx_win, img, tab);
    ft_line(mlx_ptr, mlx_win, img, tab1);

    mlx_loop(mlx_ptr);
}
