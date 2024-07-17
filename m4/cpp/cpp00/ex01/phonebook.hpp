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
    Contact _listcontact[8];

public:
    // void getinfos(void);
    PhoneBook(void);
    ~PhoneBook(void);
    void createcontact(Contact contact, int count);
    void displaycontacts(int maxcontact);
    void display_one_contact(int index);
    std::string while_search(std::string index, int maxcontact);
};

std::string check_input(std::string strinfos);
void add_condition(int *count, Contact &contact, PhoneBook &phonebook, int *maxcontact);

#endif