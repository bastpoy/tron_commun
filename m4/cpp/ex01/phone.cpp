/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:44:37 by bpoyet            #+#    #+#             */
/*   Updated: 2024/03/25 15:32:14 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook(void)
{
    std::cout << "dans le constructeur" << endl;
    return;
}

PhoneBook::~PhoneBook(void)
{
    std::cout << "dans le destructeur" << endl;
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