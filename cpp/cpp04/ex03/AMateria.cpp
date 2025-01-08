#include "AMateria.hpp"

AMateria::AMateria(void)
{
    std::cout << "Default Amateria constructor call" << std::endl;
}

AMateria::AMateria(std::string const & type)
{
    this->_type = type;
    std::cout << "Type IMateria constructor call" << std::endl;
}
AMateria::AMateria(const AMateria &copy)
{
    *this = copy;
    std::cout << "copy AMateria constructor called" << std::endl; 
}

AMateria &AMateria::operator=(const AMateria &copy)
{
    if(this != &copy)
    {
        this->_type = copy._type;
    }
    std::cout << "overload assigmement Materia operator call" << std::endl;
    return *this;
}

AMateria::~AMateria(void)
{
    std::cout << "Defaut AMateria destructor called" << std::endl;
}

// --------MEMBER FUNCTIONS--------

std::string const & AMateria::getType() const
{
    return (this->_type);
}

void AMateria::use(ICharacter& target)
{
    std::cout << "*shoots a materia bolt at " << target.getName() << " *" << std::endl;
}
