/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastpoy <bastpoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:34:11 by bpoyet            #+#    #+#             */
/*   Updated: 2024/07/09 17:38:40 by bastpoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main()
{
    // PhoneBook book;
    // Contact person[8];
    std::string string = "";
    PhoneBook repertory;

    while (string != "EXIT")
    {
        std::cout << "ADD SEARCH EXIT contact" << std::endl;
        std::cin >> string;
        if (string == "ADD")
        {
            fill_contact(repertory);
        }
        else if (string == "SEARCH")
        {
            std::cout << "SEARCH";
            return (2);
        }
        else if (string == "EXIT")
        {
            std::cout << "EXIT";
            return (3);
        }
        else
            std::cout << "Wrong command" << std::endl;
        break;
    }
    return 0;
}
