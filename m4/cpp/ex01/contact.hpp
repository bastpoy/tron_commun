#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>
#include <iostream>
#include <cerrno>
#include <stdlib.h>

class Contact
{
private:
    std::string name;
    std::string lastname;
    std::string nickname;
    std::string phonenumber;
    std::string darkestsecret;

public:
    std::string getname(void);
    std::string getlastname(void);
    std::string getnickname(void);
    std::string getphonenumber(void);
    std::string getdarkestsecret(void);
    void fill_new_contact(std::string strinfos[5]);
};

#endif