/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:34:11 by bpoyet            #+#    #+#             */
/*   Updated: 2024/03/22 16:55:01 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main()
{
    // PhoneBook book;
    // Contact person[8];
    std::string string = "";

    while (string != "EXIT")
    {
        cout << "ADD SEARCH EXIT contact" << endl;
        cin >> string;
        if (string == "ADD")
        {
            cout << "ADD";
            return (1);
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
