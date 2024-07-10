/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastpoy <bastpoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:44:37 by bpoyet            #+#    #+#             */
/*   Updated: 2024/07/09 17:38:05 by bastpoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook(void)
{
    std::cout << "dans le constructeur" << std::endl;
    return;
}

PhoneBook::~PhoneBook(void)
{
    std::cout << "dans le destructeur" << std::endl;
    return;
}

void PhoneBook::createcontact(Contact &newContact)
{
    if (indexcontact == 8)
        indexcontact = 0;
    listcontact[indexcontact] = newContact;
    indexcontact++;
}

// void PhoneBook::getinfos(void)
// {
//     int i = 0;

//     while (i < 2)
//     {
//         }
// }