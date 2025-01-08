#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    public:
        Dog(void);
        ~Dog(void);
        Dog(const Dog &copy);
        Dog &operator=(const Dog &copy);
        void makeSound();
        void printIdeas(void);
        void setIdeas(std::string ideas);
    private:
        Brain *lebrainjames;
};

#endif