/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastpoy <bastpoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:55:22 by bpoyet            #+#    #+#             */
/*   Updated: 2024/07/16 02:30:23 by bastpoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

std::string Contact::getname(void)
{
    return (this->name);
    // return (truncate(this->name));
}
std::string Contact::getlastname(void)
{
    return(this->lastname);
    // return (truncate(this->lastname));
}
std::string Contact::getnickname(void)
{
    return (this->nickname);
    // return (truncate(this->nickname));
}
std::string Contact::getphonenumber(void)
{
    return (this->phonenumber);
    // return (truncate(this->phonenumber));
}
std::string Contact::getdarkestsecret(void)
{
    return(this->darkestsecret);
    // return (truncate(this->darkestsecret));
}

void Contact::fill_new_contact(std::string strinfos[5])
{
    this->name = strinfos[0];
    this->lastname = strinfos[1];
    this->nickname = strinfos[2];
    this->phonenumber = strinfos[3];
    this->darkestsecret = strinfos[4];
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
    while (is_number(str) == 0)
    {
        std::cout << "phonenumber must be a number: ";
        std::getline(std::cin, str);
        if(std::cin.eof())
            exit(1);
    }
    return(str);
}

std::string truncate(std::string str)
{
    // if (str.length() > 10)
    // {
    //     str.resize(9);
    //     str.append(".");
    // }
    // if (str.length() < 10)
    // {
    //     while(str.length() < 10)
    //         str.insert(0," ");
    // }
    return (str);
}
