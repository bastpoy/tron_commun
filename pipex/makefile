SRCSPRINTF = main.c free.c error.c
OBJSPRINTF = $(patsubst %.c, objects/%.o, $(SRCSPRINTF))

CFLAGS = -Wall -Werror -Wextra -g3 

NAME = pipex

$(NAME) : libft/libft.a $(OBJSPRINTF)
	gcc $(CFLAGS) -o $(NAME) $(OBJSPRINTF) ./libft/libft.a
all : $(NAME)

libft/libft.a: FORCE
	$(MAKE) all -C ./libft

objects/%.o : %.c pipex.h libft/libft.h
	mkdir -p $(dir $@)
	gcc $(CFLAGS) -c $< -o $@

clean : 
	$(MAKE) clean -C ./libft
	rm -rf objects
	rm -rf test

fclean : clean
	rm -f $(NAME)

test: test.c
	gcc test.c

re : fclean all

FORCE:

.PHONY:  all clean fclean re