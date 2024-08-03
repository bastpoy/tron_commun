#include "Ice.hpp"
#include "Cure.hpp"
#include "AMateria.hpp"
#include "Character.hpp"

int main(void)
{
    AMateria *ice = new Ice();
    AMateria *cure = new Cure();
    AMateria *ice1 = ice->clone();
    AMateria *cure1 = cure->clone();
    Character *bob = new Character("bob");

    std::cout << std::endl << "------EQUIP-----"<<std::endl << std::endl;

    bob->equip(ice);
    bob->equip(cure);

    std::cout << std::endl << "------USE-----"<<std::endl << std::endl;

    bob->use(0, *bob);
    bob->use(1, *bob);

    std::cout << std::endl << "------UNEQUIP-----"<<std::endl << std::endl;

    bob->unequip(0);
    bob->unequip(1);
    bob->unequip(2);
    bob->unequip(0);

    std::cout << std::endl << std::endl;

    delete bob;
    delete ice;
    delete cure;
    delete ice1;
    delete cure1;
    return 0;
}