/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastpoy <bastpoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:34:11 by bpoyet            #+#    #+#             */
/*   Updated: 2024/07/11 18:37:17 by bastpoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook(void)
{

}

void PhoneBook::createcontact(Contact contact, int count)
{
    listcontact[count] = contact;
}

void PhoneBook::displaycontacts()
{
    int i = 0;
    std::cout << "INDEX|FIRST NAME|LAST NAME |NICKNAME  |PHONE NUM " << std::endl;
    while(!listcontact[i].getname1().empty())
    {
        std::cout << i + 1 << "    |" << listcontact[i].getname() 
            << "|" << listcontact[i].getlastname() << "|" 
            << listcontact[i].getphonenumber() << "|"
            << listcontact[i].getnickname() << std::endl;
        i++;
    }
}
void PhoneBook::display_one_contact(int index)
{
    std::cout << "INDEX|FIRST NAME|LAST NAME |NICKNAME  |PHONE NUM |SECRET" << std::endl;
    std::cout << index << "    |" << listcontact[index - 1].getname() 
        << "|" << listcontact[index - 1].getlastname() << "|"
        << listcontact[index - 1].getphonenumber() << "|"
        << listcontact[index - 1].getnickname() << "|"
        << listcontact[index - 1].getdarkestsecret() << std::endl;
}

std::string     PhoneBook::while_search(std::string index)
{
    int indexint = (int)index[0] - 48;

    while(index.length() > 1 || !isdigit(index[0]) || index[0] < '1' ||
        index[0] > '8' || this->listcontact[indexint - 1].getname1().empty())
    {
        std::cout << "Wrong Number pick another: ";
        std::cin >> index;
        if(std::cin.eof())
            exit(1);
        indexint = (int)index[0] - 48;
    }
    return(index);
}
void add_condition(int *count, Contact &contact, PhoneBook &phonebook)
{
    std::string strinfos[5];

    std::cout << "enter name: ";
    std::cin >> strinfos[0];
    if(std::cin.eof())
        exit(1);
    std::cout << "enter lastname: ";
    std::cin >> strinfos[1];
    if(std::cin.eof())
        exit(1);
    std::cout << "enter nickname: ";
    std::cin >> strinfos[2];
    if(std::cin.eof())
        exit(1);
    std::cout << "enter phonenumber: ";
    std::cin >> strinfos[3];
    if(std::cin.eof())
        exit(1);
    strinfos[3] = while_number(strinfos[3]);
    std::cout << "enter darkest secret: ";
    std::cin >> strinfos[4];
    if(std::cin.eof())
        exit(1);
    contact.fill_new_contact(strinfos);
    phonebook.createcontact(contact, *count);
    *count = *count + 1;
    if(*count == 8)  
        *count = 0;
}