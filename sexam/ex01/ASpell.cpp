#include "ASpell.hpp"

ASpell::ASpell(std::string const name, std::string const effects)
{
    this->name = name;
    this->effects = effects;
}

ASpell::~ASpell()
{}

ASpell::ASpell(const ASpell &copy)
{
    *this = copy;
}
ASpell &ASpell::operator=(const ASpell &copy)
{
    if(this != &copy)
    {
        this->name = copy.name;
        this->effects = copy.effects;
    }
    return(*this);
}

const std::string &ASpell::getName(void) const
{
    return(this->name);
}

const std::string & ASpell::getEffects(void) const
{
    return(this->effects);
}

void ASpell::launch(const ATarget &target)
{
    std::cout << target.getType() << "has been " << this->effects << std::endl;
}