#include "Ice.hpp"
#include "Cure.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main(void)
{
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
    }
    {
        std::cout << std::endl << std::endl << "CONSTRUCTOR MATERIA..."  << std::endl;

        IMateriaSource* src = new MateriaSource();
        
        std::cout << std::endl << std::endl << "LEARNING MATERIA..."  << std::endl;

        src->learnMateria(new Ice());
        src->learnMateria(new Cure());

        std::cout << std::endl << std::endl;
         
        ICharacter* me = new Character("me");
        AMateria* tmp;

        std::cout << std::endl << std::endl << "CREATE AND EQUIP MATERIA..."  << std::endl;

        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);

        std::cout << std::endl << std::endl << "USE MATERIA..."  << std::endl;

        ICharacter* bob = new Character("bob");
        me->use(0, *bob);
        me->use(1, *bob);

        std::cout << std::endl << std::endl << "DESTRUCTOR..."  << std::endl;

        delete bob;
        delete me;
        delete src;       
    }
    return 0;
}