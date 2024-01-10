/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:19:58 by bpoyet            #+#    #+#             */
/*   Updated: 2024/01/10 18:52:48 by bpoyet           ###   ########.fr       */
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

t_line ft_create_point(double xa, double xb, double ya, double yb)
{
    t_line point;
    point.xa = xa;
    point.xb = xb;
    point.ya = ya;
    point.yb = yb;

    return (point);
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

void ft_line(void *mlx_ptr, void *mlx_win, t_data img, t_line point)
{
    double coef = (point.yb - point.ya) / (point.xb - point.xa);
    double yzero = point.ya - (coef * point.xa);
    printf("yzero %f et coef %f\n", yzero, coef);
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
        if(coef > 0)
            point.xa = point.xa + incr;
        else
            point.xa = point.xa - incr;
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

    t_line line1 = ft_create_point(800, 1600, 100, 600); //segment haut long
    t_line line2 = ft_create_point(380, 1250, 467.5, 1011.25); // segment bas long
    t_line line3 = ft_create_point(800, 380, 100, 467.5); //segment gauche larg
    t_line line4 = ft_create_point(1600, 1250, 600, 1011.25); //segment droite larg

    int lengthx;
    int lengthy;
    int *lengthxy = malloc(sizeof(int) * 2);
    t_data img;

    mlx_ptr = mlx_init();
    mlx_win = mlx_new_window(mlx_ptr, 1920, 1080, "Hello world");
    img.img = mlx_new_image(mlx_ptr, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

    lengthxy = ft_get_length_width();
    lengthx = lengthxy[0]; // recupere le nombre de nombre en x
    lengthy = lengthxy[1]; // recupere le nombrede nombre en y
    printf("%d et %d\n", lengthx, lengthy);

    ft_line(mlx_ptr, mlx_win, img, line1);
    ft_line(mlx_ptr, mlx_win, img, line2);
    ft_line(mlx_ptr, mlx_win, img, line3);
    ft_line(mlx_ptr, mlx_win, img, line4);

    mlx_loop(mlx_ptr);
}
