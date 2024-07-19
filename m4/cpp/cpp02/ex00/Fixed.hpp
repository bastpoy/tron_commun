#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
    private:
        int _integer;
        static const int _bitnumber;

    public:
        Fixed(void);
        Fixed(Fixed const & value);
        ~Fixed(void);
        Fixed & operator=(Fixed const & value);
        int get_value(void) const;
};

#endif