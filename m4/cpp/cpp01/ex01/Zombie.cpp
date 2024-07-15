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

Zombie *zombieHorde(int N, std::string name)
{
    Zombie *zombies = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        zombies[i].name(name);
        zombies[i].announce();
    }
    return (zombies);
}