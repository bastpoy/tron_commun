#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

class DiamondTrap: public ScavTrap, public FragTrap
{
    private:
        std::string _name;

    public:
        DiamondTrap();
        DiamondTrap(const DiamondTrap &copy);
        ~DiamondTrap();
        DiamondTrap &operator=(const DiamondTrap &copy);
        
        void whoAmI();
};

#endif