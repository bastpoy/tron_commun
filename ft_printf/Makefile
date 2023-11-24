SRCSPRINTF = ft_chooseprint.c ft_dividhex.c ft_getprintaddr.c ft_getprintchar.c ft_getprintint.c ft_getprintuint.c ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c
OBJSPRINTF = $(patsubst %.c, objects/%.o, $(SRCSPRINTF))

LIBFTH = ./libft/libft.h 

CFLAGS = -Wall -Werror -Wextra -g

NAME = libftprintf.a

$(NAME) : $(OBJSPRINTF)
	$(MAKE) all bonus -C ./libft
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJSPRINTF)

all : $(NAME)

objects/%.o : %.c ft_printf.h $(LIBFTH)
	mkdir -p $(dir $@)
	gcc $(CFLAGS) -c $< -o $@

clean : 
	$(MAKE) clean -C ./libft
	rm -rf objects

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re : fclean all

.PHONY:  all clean fclean re