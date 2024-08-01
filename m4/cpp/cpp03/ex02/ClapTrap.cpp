#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Default"), _hitPoint(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoint(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap Name constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap Default destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
    std::cout << "ClapTrap Default constructor copy called" << std::endl;
    *this = copy;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &copy)
{
    std::cout << "ClapTrap overload egal operator" << std::endl;
    if(this != &copy)
    {
        this->_name = copy._name;
        this->_hitPoint = copy._hitPoint;
        this->_energyPoints = copy._energyPoints;
        this->_attackDamage = copy._attackDamage;
    }
    return(*this);
}

void ClapTrap::attack(const std::string& target)
{
    if(this->_energyPoints <= 0)
        std::cout << "Not enough energy points to attack" << std::endl;
    else if(this->_hitPoint <= 0)
        std::cout << this->_name << " is dead!!" << std::endl;
    else
    {
        std::cout << "ClapTrap " << this->_name << " attack " <<
            target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
        this->_energyPoints = this->_energyPoints - 1;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if(this->_hitPoint <= 0)
        std::cout << this->_name << " is dead!!" << std::endl;
    else
    {
        this->_hitPoint = this->_hitPoint - amount;
        if(this->_hitPoint <= 0)
            std::cout << this->_name << " is dead!!" << std::endl;
        else
            std::cout << "ClapTrap " << this->_name << " loose " <<
            amount << ", the life is " << this->_hitPoint << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if(this->_energyPoints <= 0)
        std::cout << "Not enough energy points to repair" << std::endl;
    else if(this->_hitPoint <= 0)
        std::cout << this->_name << " is dead!!" << std::endl;
    else
    {
        this->_energyPoints -= 1;
        this->_hitPoint += amount;
        std::cout << "ClapTrap " << this->_name << " gain " <<
        amount << " point, the life is " << this->_hitPoint << std::endl;    
    }
}