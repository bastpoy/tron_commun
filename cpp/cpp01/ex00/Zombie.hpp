#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__
#include <iostream>

class Zombie{
private:

std::string _name;

public:

void announce( void );

Zombie(std::string zombiename);
~Zombie(void);
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif