SRCSPRINTF = src/main.c src/get_next_line.c src/get_next_line_utils.c\
			src/parse.c src/ft_split.c \
			src/ft_atoi.c src/manage_struct.c src/movement.c \
			src/init.c src/hook.c src/draw.c src/color.c\
			src/apply_move1.c src/apply_move2.c src/free.c
OBJSPRINTF = $(patsubst %.c, objects/%.o, $(SRCSPRINTF))

MINILIBX = ./minilibx-linux/mlx.h

CFLAGS = -Wall -Werror -Wextra -g3

NAME = fdf.out

$(NAME) : $(OBJSPRINTF)
	$(MAKE) all -C ./minilibx-linux
	gcc $(CFLAGS) -o $(NAME) $(OBJSPRINTF) ./minilibx-linux/libmlx.a -lX11 -lXext -lm -fsanitize=address
# cp ft_printf/libftprintf.a $(NAME)
# ar rcs $(NAME) $(OBJSPRINTF)

all : $(NAME)

objects/%.o : %.c include/fdf.h include/struct.h $(MINILIBX) 
	mkdir -p $(dir $@)
	gcc $(CFLAGS) -c $< -o $@

clean : 
	$(MAKE) clean -C ./minilibx-linux
	rm -rf objects

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY:  all clean fclean re