SRCSPRINTF = main.c ft_sort.c ft_list.c ft_sort_numbers.c ft_algo.c
OBJSPRINTF = $(patsubst %.c, objects/%.o, $(SRCSPRINTF))

PRINTF = ./ft_printf/ft_printf.h 

CFLAGS = -Wall -Werror -Wextra -g

NAME = push_swap

$(NAME) : $(OBJSPRINTF)
	$(MAKE) all  -C ./ft_printf
	gcc $(CFLAGS) -o push_swap $(OBJSPRINTF) ./ft_printf/libftprintf.a -fsanitize=address
# cp ft_printf/libftprintf.a $(NAME)
# ar rcs $(NAME) $(OBJSPRINTF)

all : $(NAME)

objects/%.o : %.c push_swap.h $(PRINTF)
	mkdir -p $(dir $@)
	gcc $(CFLAGS) -c $< -o $@

clean : 
	$(MAKE) clean -C ./ft_printf
	rm -rf objects

fclean : clean
	$(MAKE) fclean -C ./ft_printf
	rm -f $(NAME)

re : fclean all

.PHONY:  all clean fclean re