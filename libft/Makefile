SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c

OBJS = ${SRCS:.c =.o}

CFLAGS = -Wall -Werror -Wextra

NAME = libft.a
HEADERS = libft.file_handling

${NAME} : ${OBJS} 
	gcc ${CFLAGS} ${OBJS} -o output

all : ${NAME}

clean : 
	rm ${OBJS}

fclean : clean
	rm ${NAME}

#re :

# NAME	=	rush-02
# CC	=	cc
# CFLAGS	=	-Wall -Werror -Wextra
# SRCS	=	./main.c		\
# 		./check_cond.c		\
# 		./input.c		\
# 		./lib1.c		\
# 		./lib2.c		\
# 		./char_to_key.c	\
# 		./file_handling.c

# OBJS	=	$(SRCS:.c=.o)
# HEADERS	=	lib.h		\

# $(NAME): $(OBJS)
# 	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# %.o: %.c $(HEADERS)
# 	$(CC) $(CFLAGS) -c $< -o $@

# all: $(NAME)

# clean:
# 	rm -f $(OBJS)

# fclean: clean
# 	rm -rf $(NAME)

# re: fclean all
