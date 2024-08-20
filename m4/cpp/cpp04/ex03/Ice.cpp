#include "Ice.hpp"

Ice::Ice(void)
{
    this->_type = "ice";
    std::cout << "default Ice constructor call" << std::endl;
}

Ice::Ice(std::string name)
{
    this->_type = name;
    std::cout << "Name constructor call" << std::endl;
}

Ice::Ice(const Ice &copy)
{
    std::cout << "Copy Ice constructor call" << std::endl;
    *this = copy;
}

Ice &Ice::operator=(const Ice &copy)
{
    if(this != &copy)
    {
        this->_type = copy._type;
    }
    std::cout << "Overload Ice assignement operator call" << std::endl;
    return (*this);
}

Ice::~Ice(void)
{
    std::cout << "Ice default destructor called" << std::endl;
}

//-----------MEMBER FUNCTION-----------

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria *Ice::clone() const 
{
    std::cout << "Ice clone call" << std::endl;
    return (new Ice(*this));
}