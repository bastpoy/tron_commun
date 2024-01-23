SRCSPRINTF = main.c get_next_line.c get_next_line_utils.c ft_manage_line.c ft_manage_entry.c ft_split.c ft_atoi.c ft_manage_struct.c
OBJSPRINTF = $(patsubst %.c, objects/%.o, $(SRCSPRINTF))

MINILIBX = ./minilibx-linux/mlx.h

CFLAGS = -Wall -Werror -Wextra -g

NAME = fdf

$(NAME) : $(OBJSPRINTF)
	$(MAKE) all -C ./minilibx-linux
	gcc $(CFLAGS) -o fdf $(OBJSPRINTF) ./minilibx-linux/libmlx.a -lX11 -lXext -lm -fsanitize=address
# cp ft_printf/libftprintf.a $(NAME)
# ar rcs $(NAME) $(OBJSPRINTF)

all : $(NAME)

objects/%.o : %.c fdf.h $(MINILIBX) 
	mkdir -p $(dir $@)
	gcc $(CFLAGS) -c $< -o $@

clean : 
	$(MAKE) clean -C ./minilibx-linux
	rm -rf objects

fclean : clean
	$(MAKE) fclean -C ./minilibx-linux
	rm -f $(NAME)

re : fclean all

.PHONY:  all clean fclean re