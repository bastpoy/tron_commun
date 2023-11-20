SRCSLIBFT = $(wildcard libft/*.c) #ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_strjoin.c ft_substr.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstmap_bonus.c ft_lstiter_bonus.c
SRCSPRINTF = ft_printf.c ft_puthex_fd.c ft_putuint_fd.c
OBJSLIBFT = $(SRCSLIBFT:.c=.o)
OBJSPRINTF= $(SRCSPRINTF:.c=.o)
LIBFTH = $(wildcard libft/libft.h)

CFLAGS = -Wall -Werror -Wextra

LIB = libftprintf.a
PRINTF = outprint

$(LIB) : $(OBJSLIBFT)
	ar rcs $(LIB) $(OBJSLIBFT) 

$(PRINTF) : $(LIB) $(OBJSPRINTF)
		gcc $(CFLAGS) -o $(PRINTF) $(OBJSPRINTF) -L. $(LIB)

all : $(PRINTF)

%.o : %.c $(LIBFTH)
	gcc $(CFLAGS) -c $< -o $@

clean : 
	rm -f $(OBJSLIBFT) $(OBJSPRINTF)

fclean : clean
	rm -f $(LIB)

re : fclean all

.PHONY:  all clean fclean re

# ifdef BONUSS
# 	OBJECTS = $(OBJS) $(OBJSB)
# else
# 	OBJECTS = $(OBJS)
# endif

# bonus : 
# 	make BONUSS=1 all