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
            std::ifstream inputFile(argv[1]);
            BitcoinExchange value;
            
            if(inputFile.is_open())
            {
                value.fillDate();
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