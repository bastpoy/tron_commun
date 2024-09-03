#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <iostream>
#include <fstream>
#include <algorithm>

class BitcoinExchange
{
    public:
        BitcoinExchange();
        ~BitcoinExchange();

        void check_date(std::ifstream &fd);


    private:
        std::map<std::string, float> keypair;
};

class InputFile : public std::exception
{
    public:
        virtual const char* what() const throw();
};

class WrongDateFormat : public std::exception
{
    public:
        virtual const char* what() const throw();
};

class CantOpeningFile : public std::exception
{
    public:
        virtual const char* what() const throw();
};

bool isSpecifiedChar(char c);

#endif