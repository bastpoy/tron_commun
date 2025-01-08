SRCSCPP = main.cpp Bureaucrat.cpp Form.cpp

OBJSCPP = $(patsubst %.cpp, objects/%.o, $(SRCSCPP))

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3

NAME = bureaucrat

$(NAME) :  $(OBJSCPP)
	c++ $(CFLAGS) -o $(NAME) $(OBJSCPP)

all : $(NAME)

objects/%.o : %.cpp Bureaucrat.hpp Form.hpp
	mkdir -p $(dir $@)
	c++ $(CFLAGS) -c $< -o $@

clean :
	rm -rf objects

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY:  all clean fclean re