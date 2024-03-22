/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:44:37 by bpoyet            #+#    #+#             */
/*   Updated: 2024/03/22 17:00:00 by bpoyet           ###   ########.fr       */
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
