#include "Dog.hpp"

Dog::Dog(void)
{
    this->_type = "Dog";
    this->lebrainjames = new Brain();
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
    {
        delete this->lebrainjames;
        this->lebrainjames = new Brain();
        this->lebrainjames = copy.lebrainjames;
        *this = copy;
    }
    return(*this);
}

Dog::~Dog(void)
{
    std::cout << "Dog default destructor" << std::endl;
    delete lebrainjames;
}

void Dog::makeSound()
{
    std::cout << "cri le chien" << std::endl;
}

void Dog::getJames()
{
    std::cout << "Je get James : " << this->lebrainjames << std::endl;
}