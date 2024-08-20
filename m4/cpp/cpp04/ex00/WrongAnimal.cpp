#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal")
{
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = copy;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
    std::cout << "WrongAnimal overload egal operator called" << std::endl;
    if(this != &copy)
        this->_type = copy._type;
    return(*this);
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::getType()
{
    std::cout << "I am a " << this->_type << std::endl;
}

void WrongAnimal::makeSound()
{
    std::cout << "cri le wrong Animal" << std::endl;
}