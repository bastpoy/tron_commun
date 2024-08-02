#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void)
{
    Animal Ani;
    Animal *cat = new Cat();
    Animal *dog = new Dog();
    WrongAnimal *wAni = new WrongCat();

    Ani.makeSound();
    cat->makeSound();
    dog->makeSound();

    Ani.getType();
    cat->getType();
    dog->getType();

    wAni->makeSound();
    wAni->getType();

    delete cat;
    delete dog;
    delete wAni;
    return 0;
}