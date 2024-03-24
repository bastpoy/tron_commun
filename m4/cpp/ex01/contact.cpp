/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:55:22 by bpoyet            #+#    #+#             */
/*   Updated: 2024/03/25 00:15:55 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Contact::Contact(void)
{
    std::cout << "dans le constructeur" << endl;
    if (this->indexcontact == 8)
    {
        this->indexcontact == 0;
    }
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
int Contact::getphonenumber(void)
{
    return phonenumber;
}
string Contact::getdarkestsecret(void)
{
    return darkestsecret;
}