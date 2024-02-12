SRCSPRINTF = src/main.c src/get_next_line.c src/get_next_line_utils.c\
			src/parse.c src/movement.c \
			src/init.c  src/free.c src/error.c src/hook.c\
			src/apply_move1.c src/apply_move2.c\
			src/draw.c
OBJSPRINTF = $(patsubst %.c, objects/%.o, $(SRCSPRINTF))

MINILIBX = ./minilibx-linux/mlx.h

CFLAGS = -Wall -Werror -Wextra -g3

NAME = fdf

$(NAME) : $(OBJSPRINTF)
	$(MAKE) all -C ./minilibx-linux
	$(MAKE) all -C ./libft
	gcc $(CFLAGS) -o $(NAME) $(OBJSPRINTF) ./minilibx-linux/libmlx.a ./libft/libft.a -lX11 -lXext -lm -fsanitize=address

all : $(NAME)

objects/%.o : %.c include/fdf.h include/struct.h libft/libft.h $(MINILIBX) 
	mkdir -p $(dir $@)
	gcc $(CFLAGS) -c $< -o $@

clean : 
	$(MAKE) clean -C ./minilibx-linux
	$(MAKE) clean -C ./libft
	rm -rf objects

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY:  all clean fclean re