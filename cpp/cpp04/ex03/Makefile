SRCSCPP = AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp main.cpp

OBJSCPP = $(patsubst %.cpp, objects/%.o, $(SRCSCPP))

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3

NAME = materia

$(NAME) :  $(OBJSCPP)
	c++ $(CFLAGS) -o $(NAME) $(OBJSCPP)

all : $(NAME)

objects/%.o : %.cpp AMateria.hpp Character.hpp Cure.hpp Ice.hpp ICharacter.hpp IMateriaSource.hpp MateriaSource.hpp
	mkdir -p $(dir $@)
	c++ $(CFLAGS) -c $< -o $@

clean :
	rm -rf objects

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY:  all clean fclean re