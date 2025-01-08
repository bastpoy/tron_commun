#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{

    if(argc < 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        return (1);
    }
    else if(argc > 2)
    {
        std::cout << "Too much arguments" << std::endl;
        return (1);
    }
    else
    {
        std::ifstream inputFile(argv[1]);
        BitcoinExchange value;
        
        if(inputFile.is_open())
        {
            value.fillDate();
            value.check_date(inputFile);
        }
        else
        {
            std::cout << "Can't open file" << std::endl;
            return (1);
        }
    }
    return (0);
}