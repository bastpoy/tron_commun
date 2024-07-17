/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastpoy <bastpoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:34:11 by bpoyet            #+#    #+#             */
/*   Updated: 2024/07/17 19:45:20 by bastpoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook(void)
{
}

PhoneBook::~PhoneBook(void)
{
}

void PhoneBook::createcontact(Contact contact, int count)
{
    _listcontact[count] = contact;
}

std::string check_input(std::string strinfos)
{
    std::getline(std::cin, strinfos);
    if(std::cin.eof())
    {
        // std::cout << "je suis la plutot" << std::endl << std::flush;
        std::cout << std::flush;
        return "";
    }
    while(!std::cin.good() || strinfos.empty())
    {
        std::cout << "Wrong entry enter again:" << std::endl << std::flush;
        std::getline(std::cin, strinfos);
        if(std::cin.eof())
        {
            std::cin.clear();
            return "";
        }
    }
    return (strinfos);
}

void PhoneBook::displaycontacts(int maxcontact)
{
    int i = 0;
    while(i < maxcontact)
    {
        std::cout << std::setw(10) << i + 1;
        std::cout << "|" << std::setw(10) << truncate(_listcontact[i].getname());
        std::cout << "|" << std::setw(10) << truncate(_listcontact[i].getlastname());
        std::cout << "|" << std::setw(10) << truncate(_listcontact[i].getnickname()) << std::endl;
        i++;
    }
}
void PhoneBook::display_one_contact(int index)
{
    std::cout << std::setw(10) << index;
    std::cout << "|" << std::setw(10) << _listcontact[index - 1].getname();
    std::cout << "|" << std::setw(10) << _listcontact[index - 1].getlastname() ;
    std::cout << "|" << std::setw(10) << _listcontact[index - 1].getnickname();
    std::cout << "|" << std::setw(10) << _listcontact[index - 1].getphonenumber();
    std::cout << "|" << std::setw(10) << _listcontact[index - 1].getdarkestsecret() << std::endl;
}

std::string     PhoneBook::while_search(std::string index, int maxcontact)
{
    int indexint = (int)index[0] - 48;

    while(index.length() > 1 || !isdigit(index[0]) || index[0] < '1' ||
        index[0] > '8' || indexint > maxcontact)
    {
        std::cout << "Wrong Number pick another: ";
        std::cin >> index;
        if(std::cin.eof())
            exit(1);
        indexint = (int)index[0] - 48;
    }
    return(index);
}

void add_condition(int *count, Contact &contact, PhoneBook &phonebook, int *maxcontact)
{
    std::string strinfos[5];

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "enter name: ";
    strinfos[0] = check_input(strinfos[0]);
    if(strinfos[0].empty() || std::cin.eof() || std::cin.eof())
        return;
    std::cout << "enter lastname: ";
    strinfos[1] = check_input(strinfos[1]);
    if(strinfos[1].empty() || std::cin.eof())
        return;
    std::cout << "enter nickname: ";
    strinfos[2] = check_input(strinfos[2]);
    if(strinfos[2].empty() || std::cin.eof())
    {
        return;
    }
    std::cout << "enter phonenumber: ";
    std::getline(std::cin, strinfos[3]);
    if(std::cin.eof())
        return;
    strinfos[3] = while_number(strinfos[3]);
    if(strinfos[3].empty() || std::cin.eof())
        return;
    std::cout << "enter darkest secret: ";
    strinfos[4] = check_input(strinfos[4]);
    if(strinfos[4].empty() || std::cin.eof())
        return;
    contact.fill_new_contact(strinfos);
    phonebook.createcontact(contact, *count);
    *count = *count + 1;
    if(*count != 9 && *maxcontact != 8)
        *maxcontact = *count;
    if(*count == 8)  
        *count = 0;
}
