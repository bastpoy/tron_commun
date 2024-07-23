#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <math.h>

class Fixed
{
    private:
        int _integer;
        static const int _bitnumber;

    public:
        Fixed(void);
        Fixed(Fixed const & copy);
        Fixed(const int value);
        Fixed(const float value);
        ~Fixed(void);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
        Fixed& operator=(Fixed const &copy);
        bool operator<(Fixed const &copy) const;
        bool operator>(Fixed const &copy) const;
        bool operator<=(Fixed const &copy) const;
        bool operator>=(Fixed const &copy) const;
        bool operator==(Fixed const &copy) const;
        bool operator!=(Fixed const &copy) const;
        Fixed operator+(Fixed const &copy);
        Fixed operator-(Fixed const &copy);
        Fixed operator*(Fixed const &copy);
        Fixed operator/(Fixed const &copy);
        Fixed& operator++(void);
        Fixed operator++(int);
        Fixed& operator--(void);
        Fixed operator--(int);
        static Fixed &min(Fixed& num1, Fixed& num2);
        static Fixed &max(Fixed& num1, Fixed& num2);
        static const Fixed &min(const Fixed& num1, const Fixed& num2);
        static const Fixed &max(const Fixed& num1, const Fixed& num2);
};

std::ostream& operator<<(std::ostream& out, Fixed const& s);

#endif