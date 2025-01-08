#include "Zombie.hpp"

Zombie::Zombie(std::string zombiename) : _name(zombiename)
{
    std::cout << "Zombie named " << _name << " is created" << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << "Zombie named " << _name << " is dead" << std::endl; 
}

void Zombie::announce( void )
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl; 
}
