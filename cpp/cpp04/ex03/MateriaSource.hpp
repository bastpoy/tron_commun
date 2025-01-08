#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class AMateria;

class MateriaSource : public IMateriaSource
{
    public:
        MateriaSource();
        MateriaSource(const MateriaSource &copy);
        MateriaSource &operator=(const MateriaSource &copy);
        ~MateriaSource();

        //MEMBER FUNCTION
        void learnMateria(AMateria *materia);
        AMateria* createMateria(std::string const & type);
};

#endif