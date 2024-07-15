#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _weapon(NULL), _name(name)
{
    std::cout << "HumanB " << this->_name << " is born" << std::endl;
}

HumanB::~HumanB(void)
{
    std::cout << "HumanB " << this->_name << " is dead" << std::endl;
}

void HumanB::attack(void)
{
    std::cout << this->_name << " attacks with his " << _weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
    this->_weapon = &weapon;
}

