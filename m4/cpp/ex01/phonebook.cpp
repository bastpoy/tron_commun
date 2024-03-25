/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:34:11 by bpoyet            #+#    #+#             */
/*   Updated: 2024/03/25 15:57:30 by bpoyet           ###   ########.fr       */
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
        cout << "ADD SEARCH EXIT contact" << endl;
        cin >> string;
        if (string == "ADD")
        {
            fill_contact(repertory);
        }
        else if (string == "SEARCH")
        {
            cout << "SEARCH";
            return (2);
        }
        else if (string == "EXIT")
        {
            cout << "EXIT";
            return (3);
        }
        else
            std::cout << "Wrong command" << endl;
        break;
    }
    return 0;
}
