#include "Cure.hpp"

Cure::Cure(void): AMateria()
{
    this->_type = "Cure";
    std::cout << "default Cure constructor call" << std::endl;
}

Cure::Cure(std::string name)
{
    this->_type = name;
    std::cout << "Name constructor call" << std::endl;
}

Cure::Cure(const Cure &copy)
{
    std::cout << "Copy Cure constructor call" << std::endl;
    *this = copy;
}

Cure &Cure::operator=(const Cure &copy)
{
    if(this != &copy)
    {
        this->_type = copy._type;
    }
    std::cout << "Overload Cure assignement operator call" << std::endl;
    return(*this);
}

Cure::~Cure(void)
{
    std::cout << "Cure default destructor called" << std::endl;
}

//-----------MEMBER FUNCTION-----------

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria *Cure::clone() const 
{
    std::cout << "Cure clone call" << std::endl;
    return (new Cure(*this));
}