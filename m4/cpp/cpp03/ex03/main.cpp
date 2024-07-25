#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
    ClapTrap clap("clap");
    ScavTrap scav;
    FragTrap frag("frag");
    DiamondTrap diamond("diamond");

    diamond.whoAmI();
    diamond.attack("frag");

    clap.attack("trap1");
    scav.takeDamage(20);
    scav.beRepaired(10);

    scav.attack("frag");
    frag.takeDamage(10);
    frag.beRepaired(5);

    frag.attack("scav");
    
    frag.highFivesGuys();
    scav.guardGate();
}