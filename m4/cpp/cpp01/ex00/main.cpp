#include "Zombie.hpp"

int main(void)
{
    std::string name;
    std::cout << "Write the first Zombie name: ";
    std::cin >> name;
    if(std::cin.eof())
        return(1);

    Zombie zombie1(name);
    zombie1.announce();

    std::cout << "Write the second Zombie name: ";
    std::cin >> name;
    if(std::cin.eof())
        return(1);

    Zombie *zombie2 = newZombie(name);
    zombie2->announce();
    delete zombie2;

    randomChump("laderdesder");
}
