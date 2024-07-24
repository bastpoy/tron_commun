#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ClapTrap clap1("clap");
    ScavTrap trap1;
    ScavTrap trap2("trap2");

    clap1.attack("trap1");
    trap1.takeDamage(20);
    trap1.beRepaired(10);

    trap1.attack("trap2");
    trap2.takeDamage(10);
    trap2.beRepaired(5);

    trap2.guardGate();
}