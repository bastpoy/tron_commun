/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastpoy <bastpoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:55:22 by bpoyet            #+#    #+#             */
/*   Updated: 2024/07/17 03:42:02 by bastpoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

std::string Contact::getname(void)
{
    return (this->_name);
}
std::string Contact::getlastname(void)
{
    return (this->_lastname);
}
std::string Contact::getnickname(void)
{
    return (this->_nickname);
}
std::string Contact::getphonenumber(void)
{
    return (this->_phonenumber);
}
std::string Contact::getdarkestsecret(void)
{
    return (this->_darkestsecret);
}

void Contact::fill_new_contact(std::string strinfos[5])
{
    this->_name = strinfos[0];
    this->_lastname = strinfos[1];
    this->_nickname = strinfos[2];
    this->_phonenumber = strinfos[3];
    this->_darkestsecret = strinfos[4];
}

int is_number(std::string str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (isdigit(str[i]) == false)
            return (0);
    }
    return (1);
}

std::string while_number(std::string str)
{
    while (is_number(str) == 0 || !std::cin.good() || str.empty())
    {
        std::cout << "phonenumber must be a number: ";
        std::getline(std::cin, str);
        if(std::cin.eof())
            return "";
    }
    return(str);
}

std::string truncate(std::string str)
{
    if (str.length() > 10)
    {
        str.resize(9);
        str.append(".");
    }
    return (str);
}
