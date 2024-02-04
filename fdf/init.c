#include "fdf.h"

t_list *ft_init_pointbegin()
{
    t_list *list;

    list = malloc(sizeof(t_list));
    list->ptrbegin = NULL;
    list->data = NULL;
    list->zmax = 0;
    return (list);
}

t_line *ft_init_tline()
{
    t_line *line;

    line = malloc(sizeof(t_line));
    line->x1 = 0;
    line->y1 = 0;
    line->x1proj = 0;
    line->y1proj = 0;
    line->z1 = 0;
    line->color = 0;
    line->index = -1;
    line->next = NULL;
    line->top = NULL;
    return (line);
}

t_list *init_data(t_list *list, t_input input)
{
    t_env *data;

    data = malloc(sizeof(t_env));
    data->angle = 0;
    data->height = 0.25;
    data->zoom = 1;
    data->offsetx = 1000;
    data->offsety = 500;
    data->mlx_ptr = mlx_init();
    data->mlx_win = mlx_new_window(data->mlx_ptr, 1920, 1080, "Hello world");
    list->data = data;
    list->input = input;
    return (list);
}