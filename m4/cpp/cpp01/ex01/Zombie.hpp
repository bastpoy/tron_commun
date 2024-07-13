#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__

#include <iostream>

class Zombie{
    std::string _name;
};

Zombie* zombieHorde( int N, std::string name );

#endif