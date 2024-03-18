SRCSPRINTF = src/philosopher.c\
			 src/utils.c\
			 src/checkargs.c\
			 src/init.c\
			 src/routine.c\
			 src/operations.c\
			 src/forks.c
OBJSPRINTF = $(patsubst %.c, objects/%.o, $(SRCSPRINTF))

CFLAGS = -Wall -Werror -Wextra -g3 -pthread

NAME = philo

$(NAME) :  $(OBJSPRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJSPRINTF)

all : $(NAME)

objects/%.o : %.c philosopher.h
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf objects
	rm -rf test

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY:  all clean fclean re