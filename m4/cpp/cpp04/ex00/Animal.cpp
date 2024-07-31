#include "Animal.hpp"

Animal::Animal(void): _type("Default")
{
    std::cout << "Animal default constructor" << std::endl;
}

Animal::Animal(const Animal &copy)
{
    std::cout << "Animal copy constructor" << std::endl;
    *this = copy;
}

Animal &Animal::operator=(const Animal &copy)
{
    std::cout << "Animal overload egal operator called" << std::endl;
    if(this != &copy)
        *this = copy;
    return(*this);
}

Animal::~Animal(void)
{
    std::cout << "Animal default destructor" << std::endl;
}

// ==============MEMBER FUNCTION==============

void Animal::getType()
{
    std::cout << "L'animal est: " << _type << std::endl;
}

void Animal::makeSound()
{
    std::cout << "cri animal" << std::endl;
}