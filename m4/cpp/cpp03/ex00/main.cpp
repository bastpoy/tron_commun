#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap first("first");
    ClapTrap second("second");

    for(int i = 0 ; i < 9 ; i++)
    {
        first.attack("second");
        second.takeDamage(1);
    }
    first.beRepaired(10);
    return(0);
}