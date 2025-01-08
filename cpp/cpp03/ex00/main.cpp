#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap first("first");
    ClapTrap second(first);

    for(int i = 0 ; i < 5 ; i++)
    {
        first.attack("second");
        second.takeDamage(2);
    }
    for(int i = 0 ; i < 6 ; i++)
    {
        first.beRepaired(10);
    }
    return(0);
}