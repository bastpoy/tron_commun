#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
    std::cout << "Diamondtrap default constructor called" << std::endl;
    this->_name = ClapTrap::_name + "_clap_name";
    this->_hitPoint = FragTrap::_hitPoint;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "Diamondtrap default destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy)
{
    std::cout << "DiamondTrap copy constructor";
    *this = copy;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy)
{
    std::cout << "DiamondTrap overload egal operator" << std::endl;
    if(this != &copy)
        *this = copy;
    return(*this);    
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name is: " << _name << " and ClapTrap Name is: " <<  ClapTrap::_name << std::endl;
}
