SRCSPRINTF = megaphone.cpp
OBJSPRINTF = $(patsubst %.cpp, objects/%.o, $(SRCSPRINTF))

CFLAGS = -Wall -Werror -Wextra -std=c++98

NAME = megaphone

$(NAME) :  $(OBJSPRINTF)
	$(CXX) $(CFLAGS) -o $(NAME) $(OBJSPRINTF)

all : $(NAME)

objects/%.o : %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CFLAGS) -c $< -o $@

clean :
	rm -rf objects

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY:  all clean fclean re