#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__

#include <iostream>

class Zombie{

    private:
    std::string _name;

    public:

    ~Zombie(void);
    void name(std::string name);
    void announce( void );
};

Zombie* zombieHorde( int N, std::string name );

#endif