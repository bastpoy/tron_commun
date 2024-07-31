#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "Animal.hpp"

class Brain
{
    public:
        Brain(void);
        ~Brain(void);
        Brain(const Brain &copy);
        Brain &operator=(const Brain &copy);

    private:
        std::string ideas[100];
};

#endif