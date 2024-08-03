#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
    public:
        Cure(void);
        Cure(std::string name);
        Cure(const Cure &copy);
        Cure &operator=(const Cure &copy);
        ~Cure(void);

        void use(ICharacter& target);
        AMateria* clone() const ;
};

#endif