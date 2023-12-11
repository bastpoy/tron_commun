SRCSPRINTF = main.c
OBJSPRINTF = $(patsubst %.c, objects/%.o, $(SRCSPRINTF))

LIBFTH = ./libft/libft.h 

CFLAGS = -Wall -Werror -Wextra -g

NAME = push_swap.a

$(NAME) : $(OBJSPRINTF)
	$(MAKE) all bonus -C ./libft
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJSPRINTF)

all : $(NAME)

objects/%.o : %.c push_swap.h $(LIBFTH)
	mkdir -p $(dir $@)
	gcc -c $< -o $@

clean : 
	$(MAKE) clean -C ./libft
	rm -rf objects

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re : fclean all

.PHONY:  all clean fclean re