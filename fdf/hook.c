#include "fdf.h"

int key_hook(int keycode, t_list *list)
{
    // printf("%d et ptr %p\n", keycode, list->data->mlx_ptr);
    if (keycode == 65307)
    {
        mlx_destroy_window(list->data->mlx_ptr, list->data->mlx_win);
        exit(0);
    }
    if (keycode == 122) // top arrow heigh++
    {
        list->data->height += 0.05;
        mlx_clear_window(list->data->mlx_ptr, list->data->mlx_win);
        elevation(list);
        ft_line_xyprojtop1(list, list->data);
    }
    if (keycode == 115) // bot arrow height --
    {
        list->data->height -= 0.05;
        mlx_clear_window(list->data->mlx_ptr, list->data->mlx_win);
        elevation(list);
        ft_line_xyprojtop1(list, list->data);
    }
    if (keycode == 100) // left arrow z rotation anti horaire
    {
        list->data->angle = PI / 100;
        mlx_clear_window(list->data->mlx_ptr, list->data->mlx_win);
        rotationz(list);
        ft_line_xyprojtop1(list, list->data);
    }
    if (keycode == 113) // right arrow z rotation horaire
    {
        list->data->angle = -PI / 100;
        mlx_clear_window(list->data->mlx_ptr, list->data->mlx_win);
        rotationz(list);
        ft_line_xyprojtop1(list, list->data);
    }
    if (keycode == 114) // zoom +
    {
        list->data->zoom /= 0.99;
        mlx_clear_window(list->data->mlx_ptr, list->data->mlx_win);
        zoom(list);
        ft_line_xyprojtop1(list, list->data);
    }
    if (keycode == 102) // zoom -
    {
        list->data->zoom *= 0.99;
        mlx_clear_window(list->data->mlx_ptr, list->data->mlx_win);
        zoom(list);
        ft_line_xyprojtop1(list, list->data);
    }
    if (keycode == 65363) // translate x+
    {
        list->data->offsetx += 1;
        mlx_clear_window(list->data->mlx_ptr, list->data->mlx_win);
        translatex(list);
        ft_line_xyprojtop1(list, list->data);
    }
    if (keycode == 65361) // translate x-
    {
        list->data->offsetx -= 1;
        mlx_clear_window(list->data->mlx_ptr, list->data->mlx_win);
        translatex(list);
        ft_line_xyprojtop1(list, list->data);
    }
    if (keycode == 65364) // translate x+
    {
        list->data->offsety += 1;
        mlx_clear_window(list->data->mlx_ptr, list->data->mlx_win);
        translatey(list);
        ft_line_xyprojtop1(list, list->data);
    }
    if (keycode == 65362) // translate x-
    {
        list->data->offsety -= 1;
        mlx_clear_window(list->data->mlx_ptr, list->data->mlx_win);
        translatey(list);
        ft_line_xyprojtop1(list, list->data);
    }
    return (0);
}

int mouse_hook()
{
    exit(0);
    return (0);
}