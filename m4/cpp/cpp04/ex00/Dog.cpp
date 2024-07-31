#include "Dog.hpp"

Dog::Dog(void)
{
    this->_type = "Dog";
    std::cout << "Dog default constructor" << std::endl;
}


Dog::Dog(const Dog &copy)
{
    std::cout << "Dog copy constructor" << std::endl;
    *this = copy;
}

Dog &Dog::operator=(const Dog &copy)
{
    std::cout << "Dog overload egal operator called" << std::endl;
    if(this != &copy)
        *this = copy;
    return(*this);
}

Dog::~Dog(void)
{
    std::cout << "Dog default destructor" << std::endl;
}

void Dog::makeSound()
{
    std::cout << "cri le chien" << std::endl;
}