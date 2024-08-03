#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class AMateria;

class IMateriaSource
{
    public:
        ~IMateriaSource() {}
        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);
};

#endif