#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{
    std::cout << "Constructors/destructors Animals array\n" << std::endl;
    {
        Animal *animal[10];

        for(int i = 0; i < 5 ; i++)
        {
            if(i % 2 == 0)
                animal[i] = new Cat();
            else
                animal[i] = new Dog();
            animal[i]->makeSound();
        }
        for(int i = 0; i < 5 ; i++)
        {
            delete animal[i];
        }
    }
    {
        std::cout << "Deep copy\n" << std::endl;
        Dog *dog1 = new Dog();
        Dog *dog2 = new Dog();
        *dog2 = *dog1;
        delete dog1;
        dog2->printIdeas();
        delete dog2;
    }

    // new Animal();

}