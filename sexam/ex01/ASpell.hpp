#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>
#include "ATarget.hpp"

class ASpell
{
    private:
        std::string name;
        std::string effects;

    public:
        ASpell(std::string const name, std::string const effects);
        ~ASpell();
        ASpell(const ASpell &copy);
        ASpell &operator=(const ASpell &copy);

        const std::string &getName(void) const;
        const std::string &getEffects(void) const;
        virtual ASpell *clone(void) const = 0;
        void launch(const ATarget &target);
};

#endif