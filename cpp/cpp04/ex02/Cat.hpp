#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    public:
        Cat(void);
        ~Cat(void);
        Cat(const Cat &copy);
        Cat &operator=(const Cat &copy);
        void makeSound();
        void printIdeas(void);
    private:
        Brain *lebrainjames;
};

#endif