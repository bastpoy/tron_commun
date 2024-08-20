#include "Character.hpp"

Character::Character()
{
    for(int i = 0; i < 4 ; i++)
    {
        this->_materia[i] = 0;
    }
    this->_name = "Default";
    std::cout << "Default Character constructor call" << std::endl;
}

Character::Character(std::string name)
{
    for(int i = 0; i < 4 ; i++)
    {
        this->_materia[i] = 0;
    }
    this->_name = name;
    std::cout << "Name Character constructor call" << std::endl;
}

Character::Character(const Character &copy)
{
    for(int i = 0; i < 4 ; i++)
    {
        this->_materia[i] = 0;
    }
    *this = copy;
    std::cout << "Copy Character constructor call" << std::endl;
}

Character &Character::operator=(const Character &copy)
{
    if(this != &copy)
    {
        for(int i = 0; i < 4 ; i++)
        {
            if(copy._materia[i])
            {
                this->_materia[i] = copy._materia[i]->clone();
            }
        }
        this->_name = copy._name;
    }
    std::cout << "Assignement overload Character operator call" << std::endl;
    return *this;
}

Character::~Character()
{
    for(int i = 0; i < 4 ; i++)
    {
        if(this->_materia[i] != 0)
            delete this->_materia[i];
    }
    std::cout << "Character default destructor call" << std::endl;
}


//------MEMBER FUNCTION------

std::string const & Character::getName() const
{
    return this->_name;
}

void Character::equip(AMateria* m)
{
    if(!m)
    {
        std::cout << "Wrong materia" << std::endl;
        return;
    }
    for(int i = 0; i < 4 ; i++)
    {
        if(!_materia[i])
        {
            _materia[i] = m;
            std::cout << "new materia " << m->getType() << " at " << i << std::endl;
            return;
        }
    }
    std::cout<< "no space left to stock metaria" << std::endl;
}

void Character::unequip(int idx)
{
    if(idx < 0 || idx > 3)
    {
        std::cout << "Wrong index" << std::endl;
        return;
    }
    else
    {
        if(_materia[idx])
        {
            AMateria *copy = _materia[idx];
            _materia[idx] = 0;
            std::cout << "materia " << copy->getType() << " at index " << idx << " unequip" << std::endl;
        }
        else
            std::cout << "Cant unequip non existent materia" << std::endl;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if(idx < 0 || idx > 3 || !_materia[idx])
    {
        std::cout << "Can't find the materia at the index: " << idx << std::endl;
        return;
    }
    std::cout << "the materia " << _materia[idx]->getType() << " at index " << idx << " ";
    _materia[idx]->use(target);
}