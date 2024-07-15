SRCSPRINTF = tests.cpp Account.cpp

OBJSPRINTF = $(patsubst %.cpp, objects/%.o, $(SRCSPRINTF))

CFLAGS = -Wall -Wextra -std=c++98 -g3

NAME = phonebook

$(NAME) :  $(OBJSPRINTF)
	c++ $(CFLAGS) -o $(NAME) $(OBJSPRINTF)

all : $(NAME)

objects/%.o : %.cpp Account.hpp
	mkdir -p $(dir $@)
	c++ $(CFLAGS) -c $< -o $@

clean :
	rm -rf objects

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY:  all clean fclean re