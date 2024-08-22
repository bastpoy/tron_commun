#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

class Base
{
    public:
        Base();
        virtual ~Base();
        Base(const Base &copy);
        Base &operator=(const Base &copy);
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif