#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
    this->_type = "WrongCat";
    std::cout << "WrongCat default constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy)
{
    std::cout << "WrongCat copy constructor" << std::endl;
    *this = copy;
}

WrongCat &WrongCat::operator=(const WrongCat &copy)
{
    std::cout << "WrongCat overload egal operator called" << std::endl;
    if(this != &copy)
    {
        this->_type = copy._type;
    }
    return(*this);
}

WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat default destructor" << std::endl;
}

void WrongCat::makeSound()
{
    std::cout << "cri le Wrong chat" << std::endl;
}