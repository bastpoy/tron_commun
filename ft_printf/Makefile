SRCSLIBFT = $(wildcard libft/*.c) 
SRCSPRINTF = ft_printf.c ft_puthex_fd.c ft_putuint_fd.c ft_dividhex.c ft_getprintaddr.c ft_getprintint.c ft_getprintperc.c ft_getprintuint.c ft_getprintchar.c ft_chooseprint.c
OBJSLIBFT = $(SRCSLIBFT:.c=.o)
OBJSPRINTF= $(SRCSPRINTF:.c=.o)

LIBFTH = $(wildcard libft/libft.h) 

CFLAGS = -Wall -Werror -Wextra -g

NAME = libftprintf.a

$(NAME) : $(OBJSPRINTF) $(OBJSLIBFT)
	$(MAKE) all bonus -C ./libft
	cp libft/libft.a $(NAME)
#$(CC) $(FLAGS) -o $(NAME)  $(OBJSPRINTF) $(OBJSLIBFT)
	ar rcs $(NAME) $(OBJSPRINTF) $(OBJSLIBFT)

all : $(NAME)

%.o : %.c $(LIBFTH) ft_printf.h
	gcc $(CFLAGS) -c $< -o $@

clean : 
	$(MAKE) clean -C ./libft
	rm -f $(OBJSLIBFT) $(OBJSPRINTF)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re : fclean all

.PHONY:  all clean fclean re

# LIB = libftprintf.a

# $(LIB) : $(OBJSLIBFT)
# 	ar rcs $(LIB) $(OBJSLIBFT) 

# $(NAME) : $(LIB) $(OBJSPRINTF)
# 		gcc $(CFLAGS) -o $(NAME) $(OBJSPRINTF) -L. $(LIB)

# ifdef BONUSS
# 	OBJECTS = $(OBJS) $(OBJSB)
# else
# 	OBJECTS = $(OBJS)
# endif

# bonus : 
# 	make BONUSS=1 all