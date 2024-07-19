#include "Fixed.hpp"

const int Fixed::_bitnumber = 8;

Fixed::Fixed(void) : _integer(0) 
{    
}

Fixed::~Fixed(void)
{
}

Fixed::Fixed(Fixed const & value)
{
    *this = value;
}

int Fixed::get_value(void) const
{
    return this->_integer;
}
