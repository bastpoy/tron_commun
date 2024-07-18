#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout << "[DEBUG]!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "[INFO]!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[WARMING]!" << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ERROR]!" << std::endl;
}

void Harl::complain( std::string level )
{
    std::string levelarray[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::* harlptr[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    int i = 0;

    while(i < 4 && level != levelarray[i])
    {
        i++;
    }
    switch(i)
    {
        case(0):
            (this->*(harlptr[0]))();
        case(1):
            (this->*(harlptr[1]))();
        case(2):
            (this->*(harlptr[2]))();
        case(3):
            (this->*(harlptr[3]))();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}
