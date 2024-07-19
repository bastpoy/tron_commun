#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int _integer;
        static const int _bitnumber;

    public:
        Fixed(void);
        Fixed(Fixed const & copy);
        ~Fixed(void);
        Fixed & operator=(Fixed const &copy);
        int get_value(void) const;
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

#endif