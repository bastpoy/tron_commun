/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastpoy <bastpoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:34:11 by bpoyet            #+#    #+#             */
/*   Updated: 2024/07/16 02:48:10 by bastpoy          ###   ########.fr       */
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

void PhoneBook::displaycontacts(int maxcontact)
{
    int i = 0;
    std::cout << "INDEX|FIRST NAME| LAST NAME|  NICKNAME| PHONE NUM" << std::endl;
    while(i < maxcontact)
    {
        // std::cout << "    "<< i + 1 << "|" << listcontact[i].getname() 
        //     << "|" << listcontact[i].getlastname() << "|" 
        //     << listcontact[i].getphonenumber() << "|"
        //     << listcontact[i].getnickname() << std::endl;
        // std::cout << std::setw(10);
        std::cout << std::setw(10) << i + 1 << "|";
        std::cout << std::setw(10) << listcontact[i].getname();
        std::cout << "|" << std::setw(10) << listcontact[i].getlastname() << "|" ;
        std::cout << std::setw(10) << listcontact[i].getphonenumber() << "|";
        std::cout << std::setw(10) << listcontact[i].getnickname() << std::endl;
        i++;
    }
}
void PhoneBook::display_one_contact(int index)
{
    std::cout << "INDEX|FIRST NAME| LAST NAME|  NICKNAME| PHONE NUM|    SECRET" << std::endl;
    // std::cout << "    "<< index << "|" << listcontact[index - 1].getname() 
    //     << "|" << listcontact[index - 1].getlastname() << "|"
    //     << listcontact[index - 1].getphonenumber() << "|"
    //     << listcontact[index - 1].getnickname() << "|"
    //     << listcontact[index - 1].getdarkestsecret() << std::endl;
    std::cout << std::setw(10) << index << "|" << std::setw(10) << 
        listcontact[index - 1].getname()  << "|" << std::setw(10)
        << listcontact[index - 1].getlastname() << "|"
        << std::setw(10) << listcontact[index - 1].getphonenumber() << "|"
        << std::setw(10) << listcontact[index - 1].getnickname() << "|"
        << std::setw(10) << listcontact[index - 1].getdarkestsecret() << std::endl;
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

    std::cout << "enter name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, strinfos[0]);
    if(std::cin.eof())
        exit(1);
    std::cout << "enter lastname: ";
    std::getline(std::cin, strinfos[1]);
    if(std::cin.eof())
        exit(1);
    std::cout << "enter nickname: ";
    std::getline(std::cin, strinfos[2]);
    if(std::cin.eof())
        exit(1);
    std::cout << "enter phonenumber: ";
    std::getline(std::cin, strinfos[3]);
    if(std::cin.eof())
        exit(1);
    strinfos[3] = while_number(strinfos[3]);
    std::cout << "enter darkest secret: ";
    std::getline(std::cin, strinfos[4]);
    if(std::cin.eof())
        exit(1);
    contact.fill_new_contact(strinfos);
    phonebook.createcontact(contact, *count);
    *count = *count + 1;
    if(*count == 8)  
        *count = 0;
    if(*count != 0)
        *maxcontact = *count;
}
