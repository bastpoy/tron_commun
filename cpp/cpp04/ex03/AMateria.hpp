#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
    protected:
        std::string _type;

    public:
        AMateria(void);
        AMateria(const AMateria &copy);
        AMateria &operator=(const AMateria &copy);
        virtual ~AMateria(void);
        AMateria(std::string const & type); // type n'est pas constant on ne peut juste pas le modifier ici
        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif