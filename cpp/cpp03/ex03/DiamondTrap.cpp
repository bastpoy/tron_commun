#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), FragTrap(), ScavTrap()
{
    std::cout << "Diamondtrap default constructor called" << std::endl;
    _name = "default";
    ClapTrap::_name = "default_clap_name";
    this->_hitPoint = FragTrap::_hitPoint;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name), FragTrap(name), ScavTrap(name)
{
    ClapTrap::_name = name + "_clap_name";
    std::cout << "Diamondtrap name constructor called" << std::endl;
    _name = name;
    _hitPoint = 100;
    _energyPoints = 50;
    _attackDamage = 30;
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
    {
        this->_name = copy._name;
        this->_hitPoint = 100;
        this->_energyPoints = 50;
        this->_attackDamage = 30;   
    }
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
