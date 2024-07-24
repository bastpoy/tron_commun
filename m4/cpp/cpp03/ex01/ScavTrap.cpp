#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
    this->_name = "default";
    this->_hitPoint = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
    this->_name = name ;
    this->_hitPoint = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap Default destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy)
{
    std::cout << "ScavTrap Default constructor copy called" << std::endl;
    *this = copy;    
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
    std::cout << "ScavTrap overload egal operator" << std::endl;
    if(this != &copy)
        *this = copy;
    return(*this);
}

void ScavTrap::attack(const std::string& target)
{
    if(this->_energyPoints <= 0)
        std::cout << "Not enough energy points to attack" << std::endl;
    else if(this->_hitPoint <= 0)
        std::cout << this->_name << " is dead!!" << std::endl;
    else
    {
        std::cout << "ScavTrap " << this->_name << "attack " <<
            target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
        this->_energyPoints = this->_energyPoints - 1;
    }    
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode" << std::endl;
}
