SRCSPRINTF = ft_chooseprint.c ft_dividhex.c ft_getprintaddr.c ft_getprintchar.c \
			 ft_getprintint.c ft_getprintuint.c ft_printf.c ft_putchar.c \
			 ft_putnbr.c ft_putstr.c ft_printcara.c
OBJSPRINTF = $(patsubst %.c, objects/%.o, $(SRCSPRINTF))

LIBFTH = ./libft/libft.h 

CFLAGS = -Wall -Werror -Wextra -g

NAME = libftprintf.a

$(NAME) : libft/libft.a $(OBJSPRINTF)
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJSPRINTF)

all : $(NAME)

libft/libft.a: FORCE
	$(MAKE) all bonus -C ./libft

objects/%.o : %.c ft_printf.h $(LIBFTH)
	mkdir -p $(dir $@)
	gcc -c $< -o $@

clean : 
	$(MAKE) clean -C ./libft
	rm -rf objects

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re : fclean all

FORCE:

.PHONY:  all clean fclean re