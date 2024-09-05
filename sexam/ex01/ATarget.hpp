#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>
#include "ASpell.hpp"

class ATarget
{
    private:
        std::string type;
    
    public:
        ATarget(const std::string type);
        ATarget(const ATarget &copy);
        ATarget &operator=(const ATarget &copy);
        ~ATarget();

        virtual ATarget *clone() const = 0 ;
        const std::string &getType(void) const;
        virtual void getHitBySpell(const ASpell &spell) const;
};

#endif