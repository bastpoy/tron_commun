#include "Span.hpp"

Span::Span(): _N(0), _index(0)
{
    this->_array = std::vector<int>(0);
}
Span::~Span()
{}
Span::Span(unsigned int N): _N(N), _index(0)
{
    this->_array = std::vector<int>(0,N);
}
Span::Span(const Span &copy): _N(copy._N)
{
    *this = copy;
}
Span &Span::operator=(const Span &copy)
{
    if(this != &copy)
    {
        this->_N = copy._N;
        _array = copy._array;
    }
    return (*this);
}

// MEMBER FUNCTIONS

void Span::addNumber(int number)
{
    if(this->_index >= this->_N)
        throw WrongArrayElement();
    this->_array.push_back(number);
    this->_index++;
}

unsigned int Span::longestSpan() const
{
    // std::vector<int>::const_iterator it;
    unsigned int gap = 0;
    if(this->_N == 0)
        throw notEnoughtElement();
    std::cout << "min " << std::min(*(this->_array.begin()), *(this->_array.end())) << std::endl; 
    gap = std::max(this->_array.begin(), this->_array.end()) - std::min(this->_array.begin(), this->_array.end()); 
    return (gap);
}

// unsigned int Span::longestSpan() const
// {

// }

void Span::printSpan() const
{
    std::vector<int>::const_iterator it;
    for(it = this->_array.begin(); it != this->_array.end(); it++)
    {
        std::cout << *it << std::endl;
    }
}

//Exceptions

const char* Span::WrongArrayElement::what() const throw()
{
    return("Out of range array element");
}

const char* Span::notEnoughtElement::what() const throw()
{
    return("Not enought element in the array");
}