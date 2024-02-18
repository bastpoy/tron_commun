SRCSPRINTF = src/main.c src/ft_sort.c src/ft_sort2.c src/ft_sort3.c\
			 src/ft_list.c src/ft_list2.c src/increment.c src/radix.c\
			 src/ft_sort_numbers.c src/ft_algo.c src/check_input.c src/free.c
OBJSPRINTF = $(patsubst %.c, objects/%.o, $(SRCSPRINTF))

PRINTF = ./ft_printf/ft_printf.h 

CFLAGS = -Wall -Werror -Wextra -g

NAME = push_swap

$(NAME) : ft_printf/libftprintf.a $(OBJSPRINTF)
	gcc $(CFLAGS) -o $(NAME) $(OBJSPRINTF) ./ft_printf/libftprintf.a
# cp ft_printf/libftprintf.a $(NAME)
# ar rcs $(NAME) $(OBJSPRINTF)

all : $(NAME)

ft_printf/libftprintf.a: FORCE
	$(MAKE) all -C ./ft_printf

objects/%.o : %.c include/push_swap.h ft_printf/ft_printf.h $(PRINTF)
	mkdir -p $(dir $@)
	gcc $(CFLAGS) -c $< -o $@

clean : 
	$(MAKE) clean -C ./ft_printf
	rm -rf objects

fclean : clean
	$(MAKE) fclean -C ./ft_printf
	rm -f $(NAME)

re : fclean all

FORCE:

.PHONY:  all clean fclean re