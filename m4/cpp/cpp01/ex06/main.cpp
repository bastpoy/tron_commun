#include "Harl.hpp"

int main(int argc, char *argv[])
{
    Harl harl;
    if(argc > 2)
        std::cout << "Too many arguments" << std::endl;
    std::string str(argv[1]);
    harl.complain(str);
    return (0);
}
