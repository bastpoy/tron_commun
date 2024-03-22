/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:18:15 by bpoyet            #+#    #+#             */
/*   Updated: 2024/03/22 17:20:11 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
using namespace std;

class PhoneBook
{

public:
    static int contactnumber
    PhoneBook(void);
    ~PhoneBook(void);
};

class Contact
{
private:
    string name;
    string lastname;
    string nickname;
    int phonenumber;
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