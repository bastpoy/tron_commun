SRCSPRINTF = src/main.c src/ft_sort.c src/ft_sort2.c src/ft_sort3.c\
			 src/ft_list.c src/ft_list2.c src/ft_list3.c \
			 src/ft_sort_numbers.c src/ft_sort_numbers2.c\
			 src/ft_algo.c src/check_input.c src/free.c\
			 src/increment.c src/increment2.c
OBJSPRINTF = $(patsubst %.c, objects/%.o, $(SRCSPRINTF))

PRINTF = ./ft_printf/ft_printf.h 

CFLAGS = -Wall -Werror -Wextra -g

NAME = push_swap

$(NAME) : $(OBJSPRINTF)
	$(MAKE) all  -C ./ft_printf
	$(MAKE) all  -C ./libft
	gcc $(CFLAGS) -o $(NAME) $(OBJSPRINTF) ./ft_printf/libftprintf.a ./libft/libft.a -fsanitize=address
# cp ft_printf/libftprintf.a $(NAME)
# ar rcs $(NAME) $(OBJSPRINTF)

all : $(NAME)

objects/%.o : %.c include/push_swap.h libft/libft.h $(PRINTF)
	mkdir -p $(dir $@)
	gcc $(CFLAGS) -c $< -o $@

clean : 
	$(MAKE) clean -C ./ft_printf
	$(MAKE) clean -C ./libft
	rm -rf objects

fclean : clean
	$(MAKE) fclean -C ./ft_printf
	rm -f $(NAME)

re : fclean all

.PHONY:  all clean fclean re