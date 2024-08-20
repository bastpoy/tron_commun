#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "Brain defaut constructor" << std::endl;
}

Brain::~Brain(void)
{
    std::cout << "Brain defaut destructor" << std::endl;
}

Brain::Brain(const Brain &copy)
{
    std::cout << "Brain copy constructor" << std::endl;
    *this = copy;
}

Brain &Brain::operator=(const Brain &copy)
{
    std::cout << "Brain overload egal operator called" << std::endl;
    if(this != &copy)
    {
        for(int i = 0; i < 100; i++)
            this->ideas[i] = copy.ideas[i];
    }
    return(*this);
}

//MEMBER FUNCTION

void Brain::setIdeas(std::string idea)
{
    for(int i = 0; i < 100; i++)
    {
        this->ideas[i] = idea;
    }
}
void Brain::printIdeas(void)
{
    int i = 0;

    while(i < 100)
    {
        std::cout << "idea " << i + 1 << ": " << this->ideas[i] << std::endl;
        i++;
    }
}