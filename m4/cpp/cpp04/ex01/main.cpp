#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{
    {
        std::cout << "CONSTRUCTOR/DESTRUCTOR ANIMAL ARRAY\n" << std::endl;
        Animal *animal[10];

        for(int i = 0; i < 5 ; i++)
        {
            std::cout << std::endl << "----CONSTRUCTEURS----" << std::endl;
            if(i % 2 == 0)
                animal[i] = new Cat();
            else
                animal[i] = new Dog();
            std::cout << std::endl << "----CRI----" << std::endl;
            animal[i]->makeSound();
        }
        std::cout << "\n----DESTRUCTOR----\n" << std::endl;
        for(int i = 0; i < 5 ; i++)
        {
            delete animal[i];
        }
    }
    {
        std::cout << "\n-----DEPP COPY-----\n" << std::endl;
        Dog *dog1 = new Dog();
        Dog *dog2 = new Dog(*dog1);
        delete dog1;
        dog2->printIdeas();
        delete dog2;
    }
}