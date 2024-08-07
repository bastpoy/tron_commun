#include "Fixed.hpp"

const int Fixed::_bitnumber = 8;

Fixed::Fixed(void) : _integer(0) 
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    std::cout << "int constructor called" << std::endl;
    this->_integer = value << this->_bitnumber;
}

Fixed::Fixed(const float value)
{
    std::cout << "float constructor called" << std::endl;
    this->_integer = roundf(value * ( 1 << 8));
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

Fixed& Fixed::operator=(Fixed const & copy)
{
    std::cout << "Copy assignement operator call" << std::endl;
    if(this != &copy)
        this->_integer = copy._integer;
    return(*this);
}

int Fixed::getRawBits( void ) const
{
    return(this->_integer);
}

void Fixed::setRawBits( int const raw )
{
    this->_integer = raw;
}

int Fixed::toInt(void) const
{
    return (float) this->_integer / 256;
}

float Fixed::toFloat( void ) const
{
    return static_cast<float>((this->_integer / (256.0f)));
}

//============ COMPAIR ============
std::ostream& operator<<(std::ostream& out, Fixed const& s)
{
    out << s.toFloat() ;
    return(out);
}
bool Fixed::operator<(Fixed const &copy) const
{
    return (this->getRawBits() < copy.getRawBits());
}
bool Fixed::operator>(Fixed const &copy) const
{
    return (this->getRawBits() > copy.getRawBits());
}
bool Fixed::operator<=(Fixed const &copy) const
{
    return (this->getRawBits() <= copy.getRawBits());
}
bool Fixed::operator>=(Fixed const &copy) const
{
    return (this->getRawBits() >= copy.getRawBits());
}
bool Fixed::operator==(Fixed const &copy) const
{
    return (this->getRawBits() == copy.getRawBits());
}
bool Fixed::operator!=(Fixed const &copy) const
{
    return (this->getRawBits() != copy.getRawBits());
}

//========== ARYTMETICC ===========
Fixed Fixed::operator+(Fixed const &copy)
{
    Fixed res;
    res._integer = this->getRawBits() + copy.getRawBits();
    return (res);
}
Fixed Fixed::operator-(Fixed const &copy)
{
    Fixed res;
    res._integer = this->getRawBits() - copy.getRawBits();
    return (res);
}
Fixed Fixed::operator*(Fixed const &copy)
{
    return (Fixed(this->toFloat() * copy.toFloat()));
}
Fixed Fixed::operator/(Fixed const &copy)
{
    return (Fixed(this->toFloat() / copy.toFloat()));
}
Fixed& Fixed::operator++(void)
{
    ++_integer;
    return(*this);
}
Fixed Fixed::operator++(int)
{
    Fixed tmp = *this;
    _integer++;
    return(tmp);
}
Fixed& Fixed::operator--(void)
{
    --_integer;
    return(*this);
}
Fixed Fixed::operator--(int)
{
    Fixed tmp = *this;
    _integer--;
    return(tmp);
}

// MAX MIN
Fixed Fixed::min(Fixed& num1, Fixed& num2)
{
    return num1.getRawBits() < num2.getRawBits() ? num1 : num2;
}
Fixed Fixed::max(Fixed& num1, Fixed& num2)
{
    return num1.getRawBits() > num2.getRawBits() ? num1 : num2;
}
const Fixed Fixed::min(const Fixed& num1, const Fixed& num2)
{
    return num1.getRawBits() < num2.getRawBits() ?num1:num2;
}
const Fixed Fixed::max(const Fixed& num1, const Fixed& num2)
{
    return num1.getRawBits() > num2.getRawBits() ?num1:num2;
}