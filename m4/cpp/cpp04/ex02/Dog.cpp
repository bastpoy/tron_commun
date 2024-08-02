#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
    this->_type = "Dog";
    this->lebrainjames = new Brain();
    this->lebrainjames->setIdeas("Dog ideas");
    std::cout << "Dog default constructor" << std::endl;
}


Dog::Dog(const Dog &copy) 
{
    this->_type = "Dog";
    this->lebrainjames = new Brain();
    this->lebrainjames->setIdeas("I am a dog");      
    std::cout << "Dog copy constructor" << std::endl;
    if(this != &copy)
        *this = copy;
}

Dog &Dog::operator=(const Dog &copy)
{
    std::cout << "Dog overload egal operator called" << std::endl;
    if(this != &copy)
    {
        if(this->lebrainjames)
            delete this->lebrainjames;
        this->lebrainjames = new Brain(*copy.lebrainjames);
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

void Dog::printIdeas(void)
{
    this->lebrainjames->printIdeas();
}