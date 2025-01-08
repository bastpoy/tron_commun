#include "Zombie.hpp"

int main(void)
{
    std::string name = "first zombie";
    std::string name2 = "second zombie";

    Zombie zombie1(name);
    zombie1.announce();

    Zombie *zombie2;
    zombie2 = newZombie(name2);
    zombie2->announce();
    delete zombie2;

    randomChump("laderdesder");
}
