SRCSCPP = main.cpp Bureaucrat.cpp\
		AForm.cpp ShrubberyCreationForm.cpp\
		RobotomyRequestForm.cpp PresidentialPardonForm.cpp

OBJSCPP = $(patsubst %.cpp, objects/%.o, $(SRCSCPP))

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3

NAME = bureaucrat

$(NAME) :  $(OBJSCPP)
	c++ $(CFLAGS) -o $(NAME) $(OBJSCPP)

all : $(NAME)

objects/%.o : %.cpp Bureaucrat.hpp AForm.hpp\
			ShrubberyCreationForm.hpp RobotomyRequestForm.hpp\
			PresidentialPardonForm.hpp
	mkdir -p $(dir $@)
	c++ $(CFLAGS) -c $< -o $@

clean :
	rm -rf objects

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY:  all clean fclean re