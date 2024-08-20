#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
    for(int i = 0; i < 4 ; i++)
    {
        this->_materiasource[i] = 0;
    }    
    std::cout << "defaut MateriaSource constructor call" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
    std::cout << "Copy assignment MateriaSource constructor call" << std::endl;
    *this = copy;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &copy)
{
    if(this != &copy)
    {
        for(int i = 0; i < 4 ; i++)
        {
            if(copy._materiasource[i])
            {
                this->_materiasource[i] = copy._materiasource[i]->clone();
            }
        }       
    }
    std::cout << "Assignement overload Materiasource operator call" << std::endl;
    return *this;
}

MateriaSource::~MateriaSource(void)
{
    for(int i = 0; i < 4 ; i++)
    {
        if(this->_materiasource[i] != 0)
            delete this->_materiasource[i];
    }    
    std::cout << "Default materia source destructor call" << std::endl;
}

// --------MEMBER FUNCTION--------

void MateriaSource::learnMateria(AMateria *materia)
{
    if(!materia)
    {
        std::cout << "Cant find materia" << std::endl;
        return;
    }
    for(int i = 0; i < 4 ; i++)
    {
        if(!_materiasource[i])
        {
            this->_materiasource[i] = materia;
            std::cout << "Materia of type " << materia->getType() << " add in inventory";
            std::cout << " at index " << i << std::endl;
            return;
        }
    }
    std::cout << "Cant add materia in inventory" << std::endl; 
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for(int i = 0 ; i < 4 ; i++)
    {
        if(this->_materiasource[i] && this->_materiasource[i]->getType() == type)
        {
            std::cout << "create materia at index: " << i << std::endl;
            return(this->_materiasource[i]->clone());
        }
    }
    std::cout << "cant find materia with this type" << std::endl;
    return NULL;
}