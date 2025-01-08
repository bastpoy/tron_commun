#include "Cat.hpp"

Cat::Cat(void)
{
    this->_type = "Cat";
    std::cout << "Cat default constructor" << std::endl;
}


Cat::Cat(const Cat &copy)
{
    std::cout << "Cat copy constructor" << std::endl;
    *this = copy;
}

Cat &Cat::operator=(const Cat &copy)
{
    std::cout << "Cat overload egal operator called" << std::endl;
    if(this != &copy)
        this->_type = copy._type;
    return(*this);
}

Cat::~Cat(void)
{
    std::cout << "Cat default destructor" << std::endl;
}

void Cat::makeSound()
{
    std::cout << "cri le chat" << std::endl;
}
