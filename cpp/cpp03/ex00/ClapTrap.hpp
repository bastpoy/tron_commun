#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    private:
        std::string _name;
        int _hitPoint;
        int _energyPoints;
        int _attackDamage;
    
    public:
        ClapTrap(void);
        
        ClapTrap(std::string name);
        ClapTrap(ClapTrap const &copy);
        ~ClapTrap(void);
        ClapTrap &operator=(ClapTrap const &copy);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif