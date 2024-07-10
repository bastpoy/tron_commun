#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <cerrno>
#include <cstdlib>
#include "contact.hpp"


class PhoneBook
{
private:
    Contact listcontact[8];
    int indexcontact;

public:
    // void getinfos(void);
    void createcontact(Contact &newContact);
};

#endif