/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:18:15 by bpoyet            #+#    #+#             */
/*   Updated: 2024/03/25 15:56:42 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <cerrno>
#include <cstdlib>

using namespace std;

class Contact
{
private:
    string name;
    string lastname;
    string nickname;
    string phonenumber;
    string darkestsecret;

public:
    Contact(void);
    ~Contact(void);
    string getname(void);
    string getlastname(void);
    string getnickname(void);
    string getphonenumber(void);
    string getdarkestsecret(void);
    void fill_new_contact(string strinfos[5]);
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