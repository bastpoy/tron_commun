#include "phonebook.hpp"

int main()
{
    std::string input = "";
    std::string index = "";
    PhoneBook repertory;
    Contact contact;
    int count = 0;
    int maxcontact = 0;

    while (input.find("EXIT") == std::string::npos)
    {
        std::cout << "ADD SEARCH EXIT contact" << std::endl;
        std::cin >> input;
        if(std::cin.eof())
            return (1);
        if (input == "ADD")
        {
            add_condition(&count, contact, repertory, &maxcontact);
        }
        else if (input == "SEARCH")
        {
            if(maxcontact != 0)
            {
                repertory.displaycontacts(maxcontact);
                std::cout << "enter index: ";
                std::cin >> index;
                if(std::cin.eof())
                    return(1);
                index = repertory.while_search(index, maxcontact);
                repertory.display_one_contact((int)index[0] - 48);
            }
            else
                std::cout << "No contact to display" << std::endl;
        }
        else if (input == "EXIT")
        {
            std::cout << "EXIT";
            return (3);
        }
        else
            std::cout << "Wrong command" << std::endl;
    }
    return 0;
}
