#include <iostream>
#include "Fixed.hpp"

int main( void ) 
{
    Fixed a;
    Fixed b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << std::endl << b << std::endl;

    Fixed c(15.4f);
    Fixed d(4);

    std::cout << c.operator+(d) << std::endl;
    std::cout << c.operator-(d) << std::endl;
    std::cout << c.operator*(d) << std::endl;
    std::cout << c.operator/(d) << std::endl;

    a.setRawBits(5);
    b.setRawBits(6);

    std::cout << Fixed::min( a, b ).getRawBits() << std::endl;
    std::cout << Fixed::max( a, b ).getRawBits() << std::endl;
    std::cout << a.operator>(b) << std::endl;
    std::cout << a.operator>=(b) << std::endl;
    std::cout << a.operator<(b) << std::endl;
    std::cout << a.operator<=(b) << std::endl;
    std::cout << a.operator==(b) << std::endl;
    std::cout << a.operator!=(b) << std::endl;

    return 0;
}