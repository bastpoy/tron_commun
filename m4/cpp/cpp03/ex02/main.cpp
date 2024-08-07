#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    ClapTrap *trap1 = new ScavTrap("Scav");
    ClapTrap trap2;
    ClapTrap *trap3 = new FragTrap("Frag");
    FragTrap trap4("Frag2");

    trap1->attack("trap2");
    trap1->takeDamage(20);
    trap1->beRepaired(10);

    trap2.attack("trap1");
    trap2.takeDamage(20);
    trap2.beRepaired(10);

    trap3->attack("trap2");
    trap3->takeDamage(20);
    trap3->beRepaired(10);    
    
    trap4.highFivesGuys();

    delete trap1;
    delete trap3;
}