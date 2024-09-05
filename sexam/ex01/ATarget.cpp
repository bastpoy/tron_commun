#include "ATarget.hpp"


ATarget::ATarget(const std::string type)
{
    this->type = type;
}

ATarget::ATarget(const ATarget &copy)
{
    *this = copy;
}

ATarget &ATarget::operator=(const ATarget &copy)
{
    if(this != &copy)
    {
        this->type = copy.type;
    }
    return (*this);
}

ATarget::~ATarget()
{}
const std::string &ATarget::getType() const
{
    return (this->type);
}
