#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{
    Animal Ani;
    Animal *cat = new Cat();
    Animal *dog = new Dog();

    Ani.makeSound();
    cat->makeSound();
    dog->makeSound();

    Ani.getType();
    cat->getType();
    dog->getType();

    delete cat;
    delete dog;
    return 0;
}