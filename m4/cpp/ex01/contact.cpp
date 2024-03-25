/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:55:22 by bpoyet            #+#    #+#             */
/*   Updated: 2024/03/25 15:54:30 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Contact::Contact(void)
{
    std::cout << "dans le constructeur" << endl;
    return;
}

Contact::~Contact(void)
{
    std::cout << "dans le constructeur" << endl;
    return;
}

string Contact::getname(void)
{
    return name;
}
string Contact::getlastname(void)
{
    return lastname;
}
string Contact::getnickname(void)
{
    return nickname;
}
string Contact::getphonenumber(void)
{
    return phonenumber;
}
string Contact::getdarkestsecret(void)
{
    return darkestsecret;
}
void Contact::fill_new_contact(string strinfos[5])
{

    name = strinfos[0];
    lastname = strinfos[1];
    nickname = strinfos[2];
    phonenumber = strinfos[3];
    darkestsecret = strinfos[4];
}