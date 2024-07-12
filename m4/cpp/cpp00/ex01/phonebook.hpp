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
    Contact listcontact[9];

public:
    // void getinfos(void);
    PhoneBook(void);
    void createcontact(Contact contact, int count);
    void displaycontacts();
    void display_one_contact(int index);
    std::string while_search(std::string index);
};

void add_condition(int *count, Contact &contact, PhoneBook &phonebook);

#endif