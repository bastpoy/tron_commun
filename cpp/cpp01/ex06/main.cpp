#include "Harl.hpp"

int main(int argc, char *argv[])
{
    Harl harl;
    if(argc != 2)
    {
        std::cout << "Wrong numbers of arguments" << std::endl;
        return (1);
    }
    std::string str(argv[1]);
    harl.complain(str);
    return (0);
}
