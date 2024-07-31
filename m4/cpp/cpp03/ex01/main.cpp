#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ClapTrap *trap1 = new ScavTrap("scav");
    ClapTrap trap2;
    ScavTrap trap3("scav2");

    trap1->attack("trap2");
    trap1->takeDamage(5);
    trap1->beRepaired(10);

    trap2.attack("trap1");
    trap2.takeDamage(5);
    trap2.beRepaired(10);

    trap3.guardGate();

    delete trap1;
}