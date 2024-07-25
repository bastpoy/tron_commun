#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    ClapTrap clap("clap");
    ScavTrap scav("scav");
    FragTrap frag("frag");

    clap.attack("scav");
    scav.takeDamage(20);
    scav.beRepaired(10);

    scav.attack("frag");
    frag.takeDamage(10);
    frag.beRepaired(5);

    scav.guardGate();
    frag.highFivesGuys();
}