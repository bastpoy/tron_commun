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
        // Forme canonique
        Fixed(void);
        Fixed(Fixed const & copy);
        Fixed(const int value);
        Fixed(const float value);
        ~Fixed(void);
        Fixed & operator=(Fixed const &copy);

        //methodes
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& out, Fixed const& s);

#endif