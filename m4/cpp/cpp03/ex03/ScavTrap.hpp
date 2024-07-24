#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    public:
        ScavTrap(void);
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &copy);
        ~ScavTrap(void);
        ScavTrap &operator=(const ScavTrap &copy);
        
        void attack(const std::string& target);
        void guardGate();
};

#endif