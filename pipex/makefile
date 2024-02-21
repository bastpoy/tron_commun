SRCSPRINTF = main.c free.c
OBJSPRINTF = $(patsubst %.c, objects/%.o, $(SRCSPRINTF))

CFLAGS = -Wall -Werror -Wextra -g3 

NAME = pipex

$(NAME) : libft/libft.a $(OBJSPRINTF)
	gcc $(CFLAGS) -o $(NAME) $(OBJSPRINTF) ./libft/libft.a -fsanitize=address

all : $(NAME)

libft/libft.a: FORCE
	$(MAKE) all -C ./libft

objects/%.o : %.c pipex.h libft/libft.h
	mkdir -p $(dir $@)
	gcc $(CFLAGS) -c $< -o $@

clean : 
	$(MAKE) clean -C ./libft
	rm -rf objects

fclean : clean
	rm -f $(NAME)

re : fclean all

FORCE:

.PHONY:  all clean fclean re