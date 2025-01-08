#include "Zombie.hpp"

void randomChump( std::string name )
{
    Zombie mec(name);
    mec.announce();
}