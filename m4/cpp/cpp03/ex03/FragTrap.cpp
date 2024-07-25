#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
    this->_name = "default";
    this->_hitPoint = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
    this->_name = name ;
    this->_hitPoint = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap Default destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy)
{
    std::cout << "FragTrap Default constructor copy called" << std::endl;
    *this = copy;    
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
    std::cout << "FragTrap overload egal operator" << std::endl;
    if(this != &copy)
        *this = copy;
    return(*this);
}

void FragTrap::attack(const std::string& target)
{
    if(this->_energyPoints <= 0)
        std::cout << "Not enough energy points to attack" << std::endl;
    else if(this->_hitPoint <= 0)
        std::cout << this->_name << " is dead!!" << std::endl;
    else
    {
        std::cout << "FragTrap " << this->_name << "attack " <<
            target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
        this->_energyPoints = this->_energyPoints - 1;
    }    
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << this->_name << " is a positive high five request" << std::endl;
}