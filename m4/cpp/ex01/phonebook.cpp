/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:34:11 by bpoyet            #+#    #+#             */
/*   Updated: 2024/07/10 23:24:22 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void PhoneBook::createcontact(Contact &newContact)
{
    if (indexcontact == 8)
        indexcontact = 0;
    listcontact[indexcontact] = newContact;
    indexcontact++;
}
