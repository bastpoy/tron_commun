/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 00:16:14 by bpoyet            #+#    #+#             */
/*   Updated: 2024/03/25 16:47:27 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

static string write_infos(string str)
{
    // cin.ignore();
    while (str.empty())
    {
        if (!getline(cin, str))
            exit(errno);
        cout << str << endl;
        if (str.empty())
            cout << "Cannot be empty: " << endl;
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
    string strinfos[5];

    cout << "First name: " << endl;
    write_infos(strinfos[0]);
    cout << "Last name: " << endl;
    write_infos(strinfos[1]);
    cout << "Nickname: " << endl;
    write_infos(strinfos[2]);
    cout << "Phone number: " << endl;
    write_infos(strinfos[3]);
    cout << "Darkest secret: " << endl;
    write_infos(strinfos[4]);
    newContact.fill_new_contact(strinfos);
    repertory.createcontact(newContact);
    return;
}
