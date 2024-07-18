#include "Zombie.hpp"

Zombie::Zombie(std::string zombiename) : _name(zombiename)
{

}

Zombie::~Zombie(void)
{
    std::cout << "Zombie named " << _name << " is dead" << std::endl; 
}

void Zombie::announce( void )
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl; 
}
