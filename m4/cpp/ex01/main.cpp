#include "contact.hpp"
#include "phonebook.hpp"

int main()
{
    std::string string = "";
    PhoneBook repertory;

    while (string.find("EXIT") == std::string::npos)
    {
        std::cout << "ADD SEARCH EXIT contact" << std::endl;
        std::cin >> string;
        if (string == "ADD")
        {
            // fill_contact(repertory);
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