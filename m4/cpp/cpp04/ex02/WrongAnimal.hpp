#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
    public:
        WrongAnimal(void);
        WrongAnimal(const WrongAnimal &copy);
        virtual ~WrongAnimal(void);
        WrongAnimal &operator=(const WrongAnimal &copy);
        void getType();
        void makeSound();
    protected:
        std::string _type;
};

#endif