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
        int get_value(void) const;
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
        bool operator<(Fixed const &copy);
        bool operator>(Fixed const &copy);
        bool operator<=(Fixed const &copy);
        bool operator>=(Fixed const &copy);
        bool operator==(Fixed const &copy);
        bool operator!=(Fixed const &copy);
        Fixed operator+(Fixed const &copy);
        Fixed operator-(Fixed const &copy);
        Fixed operator*(Fixed const &copy);
        Fixed operator/(Fixed const &copy);

};

std::ostream& operator<<(std::ostream& out, Fixed const& s);

#endif