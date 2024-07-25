#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
    std::cout << "Diamondtrap default constructor called" << std::endl;
    _name = "default";
    ClapTrap::_name = "default_clap_name";
    this->_hitPoint = FragTrap::_hitPoint;
    std::cout << "hit point: " << _hitPoint << std::endl;
    this->_energyPoints = ScavTrap::_energyPoints;
    std::cout << "energypointt: " << _energyPoints << std::endl;
    this->_attackDamage = FragTrap::_attackDamage;
    std::cout << "attackdamage: " << _attackDamage << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): FragTrap(name), ScavTrap(name)
{
    _name = name;
    std::cout << "Diamondtrap name default constructor called" << std::endl;
    ClapTrap::_name = name + "_clap_name";
    this->_hitPoint = FragTrap::_hitPoint;
    std::cout << "hit point: " << this->_hitPoint << std::endl;
    this->_energyPoints = ScavTrap::_energyPoints;
    std::cout << "energypointt: " << this->_energyPoints << std::endl;
    this->_attackDamage = FragTrap::_attackDamage;
    std::cout << "attackdamage: " << this->_attackDamage << std::endl;
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
