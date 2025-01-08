#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>
#include <iostream>
#include <cerrno>
#include <stdlib.h>
#include <iomanip>
#include <limits>

class Contact
{
private:
    std::string _name;
    std::string _lastname;
    std::string _nickname;
    std::string _phonenumber;
    std::string _darkestsecret;

public:
    std::string getname(void);
    std::string getlastname(void);
    std::string getnickname(void);
    std::string getphonenumber(void);
    std::string getdarkestsecret(void);
    void fill_new_contact(std::string strinfos[5]);
};

int is_number(std::string str);
std::string while_number(std::string str);
std::string truncate(std::string str);

#endif