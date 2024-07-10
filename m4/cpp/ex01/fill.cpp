/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastpoy <bastpoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 00:16:14 by bpoyet            #+#    #+#             */
/*   Updated: 2024/07/09 17:50:22 by bastpoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

static std::string write_infos(std::string str)
{
    // cin.ignore();
    while (str.empty())
    {
        if (!getline(std::cin, str))
            exit(errno);
        std::cout << str << std::endl;
        if (str.empty())
            std::cout << "Cannot be empty: " << std::endl;
    }
    return (str);
}

void fill_contact(PhoneBook repertory)
{
    // string firstname = "";
    // string lastname = "";
    // string nickname = "";
    // string phonenumber = "";
    // string darkestsecret = "";
    Contact newContact;
    std::string strinfos[5];

    std::cout << "First name: " << std::endl;
    write_infos(strinfos[0]);
    std::cout << "Last name: " << std::endl;
    write_infos(strinfos[1]);
    std::cout << "Nickname: " << std::endl;
    write_infos(strinfos[2]);
    std::cout << "Phone number: " << std::endl;
    write_infos(strinfos[3]);
    std::cout << "Darkest secret: " << std::endl;
    write_infos(strinfos[4]);
    newContact.fill_new_contact(strinfos);
    repertory.createcontact(newContact);
    return;
}
