#include "Zombie.hpp"

Zombie::~Zombie(void)
{
    std::cout << "Zombie named " << _name << " is dead" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::name(std::string name)
{
    _name = name;
}
