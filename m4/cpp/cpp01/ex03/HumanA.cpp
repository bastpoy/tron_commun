#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _weapon(weapon), _name(name)
{
    std::cout << "HumanA " << this->_name << " is born" << std::endl;
}

HumanA::~HumanA(void)
{
    std::cout << "HumanA " << this->_name << " is dead" << std::endl;
}

void HumanA::attack(void)
{
    std::cout << this->_name << " attacks with his " << _weapon.getType() << std::endl;
}