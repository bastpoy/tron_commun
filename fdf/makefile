SRCSPRINTF = src/main.c src/get_next_line.c src/get_next_line_utils.c\
			src/parse.c src/autofocus.c src/utils.c src/color.c\
			src/init.c  src/free.c src/error.c src/hook.c\
			src/apply_move1.c src/apply_move2.c\
			src/draw.c
OBJSPRINTF = $(patsubst %.c, objects/%.o, $(SRCSPRINTF))

MINILIBX = ./minilibx-linux/mlx.h

CFLAGS = -Wall -Werror -Wextra -g3 

NAME = fdf

$(NAME) : libft/libft.a $(OBJSPRINTF)
	$(MAKE) all -C ./minilibx-linux
	gcc $(CFLAGS) -o $(NAME) $(OBJSPRINTF) ./minilibx-linux/libmlx.a ./libft/libft.a -lX11 -lXext -lm -fsanitize=address

all : $(NAME)

libft/libft.a: FORCE
	$(MAKE) all -C ./libft

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

FORCE:

.PHONY:  all clean fclean re