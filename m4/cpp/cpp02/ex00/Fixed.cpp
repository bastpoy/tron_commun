#include "Fixed.hpp"

const int Fixed::_bitnumber = 8;

Fixed::Fixed(void) : _integer(0) 
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

int Fixed::get_value(void) const
{
    return this->_integer;
}

Fixed & Fixed::operator=(Fixed const & copy)
{
    std::cout << "Copy assignement operator call" << std::endl;
    if(this != &copy)
        this->_integer = copy.getRawBits();
    return(*this);
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return(this->_integer);
}

void Fixed::setRawBits( int const raw )
{
    this->_integer = raw;
}

