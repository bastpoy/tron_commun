#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
    public:
        Animal(void);
        Animal(const Animal &copy);
        virtual ~Animal(void);
        Animal &operator=(const Animal &copy);
        void getType();
        virtual void makeSound() = 0;
    protected:
        std::string _type;
};

#endif