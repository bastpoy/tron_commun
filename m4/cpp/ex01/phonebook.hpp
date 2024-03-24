/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:18:15 by bpoyet            #+#    #+#             */
/*   Updated: 2024/03/25 00:15:12 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
using namespace std;

class PhoneBook
{
private:
    Contact listcontact[8];

public:
    PhoneBook(void);
    ~PhoneBook(void);
    void getinfos(void);
};

class Contact
{
private:
    string name;
    string lastname;
    string nickname;
    int phonenumber;
    int indexcontact;
    string darkestsecret;

public:
    Contact(void);
    ~Contact(void);
    string getname(void);
    string getlastname(void);
    string getnickname(void);
    int getphonenumber(void);
    string getdarkestsecret(void);
};

#endif