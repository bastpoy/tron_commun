#ifndef FLAGTRAP_HPP
#define FLAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap(void);
        FragTrap(std::string name);
        FragTrap(const FragTrap &copy);
        ~FragTrap(void);
        FragTrap &operator=(const FragTrap &copy);
        
        void attack(const std::string& target);
        void highFivesGuys();        
};

#endif