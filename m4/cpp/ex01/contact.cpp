/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastpoy <bastpoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:55:22 by bpoyet            #+#    #+#             */
/*   Updated: 2024/07/09 17:53:46 by bastpoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Contact::Contact(void)
{
    std::cout << "dans le constructeur" << std::endl;
    return;
}

Contact::~Contact(void)
{
    std::cout << "dans le constructeur" << std::endl;
    return;
}

std::string Contact::getname(void)
{
    return name;
}
std::string Contact::getlastname(void)
{
    return lastname;
}
std::string Contact::getnickname(void)
{
    return nickname;
}
std::string Contact::getphonenumber(void)
{
    return phonenumber;
}
std::string Contact::getdarkestsecret(void)
{
    return darkestsecret;
}
void Contact::fill_new_contact(std::string strinfos[5])
{
    name = strinfos[0];
    lastname = strinfos[1];
    nickname = strinfos[2];
    phonenumber = strinfos[3];
    darkestsecret = strinfos[4];
}