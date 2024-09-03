#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::~BitcoinExchange()
{}

// FUNCTIONS

void BitcoinExchange::check_date(std::ifstream &fd)
{
    std::string line;
    size_t pos;
    size_t i = 0;

    while(getline(fd, line))
    {
        std::cout << line << std::endl;
        pos = line.find("|");
        if(pos != 11 && i != 0)
        {
            throw WrongDateFormat();
        }
        else if(i != 0) 
            line = line.substr(0, pos);
        for( std::string::iterator it = line.begin(); it!=line.end(); ++it)
        {
            if(!isSpecifiedChar(*it) && i != 0)
                throw WrongDateFormat();
        }
        std::cout << line << std::endl;

        // CHECK SI INFERIEUR AU FLOAT MIN ET MAX
        // CHECK PROBLEME DE SYNTAXE ENTRE LES DEUX
        i++;
    }
}

bool isSpecifiedChar(char c)
{
    if((c > 47 && c < 58) || c == '-' || c == ' ')
        return(true);
    else
        return(false);
}

// EXCEPTIONS

const char *InputFile::what() const throw()
{
    return "wrong arguments";
}

const char *WrongDateFormat::what() const throw()
{
    return "Wrong format Date";
}

const char *CantOpeningFile::what() const throw()
{
    return "Cant opening file";
}
