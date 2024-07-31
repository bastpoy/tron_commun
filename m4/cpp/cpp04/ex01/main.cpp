#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{
    Animal animal;
    Dog *scooby = new Dog();
    Dog *scooby2(scooby);
    delete scooby;
    scooby2->getJames();
    scooby->getJames();
}