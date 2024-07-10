/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:55:22 by bpoyet            #+#    #+#             */
/*   Updated: 2024/07/10 23:54:07 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "phonebook.hpp"
#include "contact.hpp"

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

void fill_contact(void)
{
    
}

// static std::string write_infos(std::string str)
// {
//     // cin.ignore();
//     while (str.empty())
//     {
//         if (!getline(std::cin, str))
//             exit(errno);
//         std::cout << str << std::endl;
//         if (str.empty())
//             std::cout << "Cannot be empty: " << std::endl;
//     }
//     return (str);
// }
