/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastpoy <bastpoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:18:15 by bpoyet            #+#    #+#             */
/*   Updated: 2024/07/09 17:50:03 by bastpoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <cerrno>
#include <cstdlib>
class Contact
{
private:
    std::string name;
    std::string lastname;
    std::string nickname;
    std::string phonenumber;
    std::string darkestsecret;

public:
    Contact(void);
    ~Contact(void);
    std::string getname(void);
    std::string getlastname(void);
    std::string getnickname(void);
    std::string getphonenumber(void);
    std::string getdarkestsecret(void);
    void fill_new_contact(std::string strinfos[5]);
};

class PhoneBook
{
private:
    Contact listcontact[8];
    int indexcontact;

public:
    PhoneBook(void);
    ~PhoneBook(void);
    // void getinfos(void);
    void createcontact(Contact &newContact);
};

void fill_contact(PhoneBook repertory);

#endif