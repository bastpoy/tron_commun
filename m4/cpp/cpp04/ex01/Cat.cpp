#include "Cat.hpp"

Cat::Cat(void)
{
    this->_type = "Cat";
    this->lebrainjames = new Brain();
    this->lebrainjames->setIdeas("Cat ideas");
    std::cout << "Cat default constructor" << std::endl;
}


Cat::Cat(const Cat &copy)
{
    std::cout << "Cat copy constructor" << std::endl;
    this->_type = "Cat";
    this->lebrainjames = new Brain();
    this->lebrainjames->setIdeas("Cat Ideas"); 
    *this = copy;
}

Cat &Cat::operator=(const Cat &copy)
{
    std::cout << "Cat overload egal operator called" << std::endl;
    if(this != &copy)
    {
        delete this->lebrainjames;
        this->lebrainjames = new Brain(*copy.lebrainjames);
    }
    return(*this);
}

Cat::~Cat(void)
{
    std::cout << "Cat default destructor" << std::endl;
    delete lebrainjames;
}

void Cat::makeSound()
{
    std::cout << "cri le chat" << std::endl;
}
