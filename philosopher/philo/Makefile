SRCSPRINTF = src/philosopher.c src/utils.c src/checkargs.c
OBJSPRINTF = $(patsubst %.c, objects/%.o, $(SRCSPRINTF))

CFLAGS = -Wall -Werror -Wextra -g3 -pthread

NAME = philosopher

$(NAME) :  $(OBJSPRINTF)
	gcc $(CFLAGS) -o $(NAME) $(OBJSPRINTF)

all : $(NAME)

objects/%.o : %.c philosopher.h
	mkdir -p $(dir $@)
	gcc $(CFLAGS) -c $< -o $@

clean :
	rm -rf objects
	rm -rf test

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY:  all clean fclean re