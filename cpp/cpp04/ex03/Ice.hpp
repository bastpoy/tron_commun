#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
    public:
        Ice(void);
        Ice(std::string name);
        Ice(const Ice &copy);
        Ice &operator=(const Ice &copy);
        ~Ice(void);

        void use(ICharacter& target);
        AMateria* clone() const ;
};

#endif