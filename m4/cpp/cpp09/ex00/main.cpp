#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    try
    {
        if(argc != 2)
        {
            std::cout << "No input file or too much arguments" << std::endl;
            throw CantOpeningFile();
        }
        else
        {
            BitcoinExchange value;
            std::ifstream inputFile(argv[1]);
            
            if(inputFile.is_open())
            {
                value.check_date(inputFile);
            }
            else
            {
                throw CantOpeningFile();
            }
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}