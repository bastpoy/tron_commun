#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <cstdlib>

#include<bits/stdc++.h> 

class BitcoinExchange
{
    public:
        BitcoinExchange();
        ~BitcoinExchange();

        void check_date(std::ifstream &fd);
        float check_value(std::string line);
        void fillDate(void);
        void dateInData(std::string date, float value);

    private:
        std::map<std::string, float> _keypair;
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

class FirstLineError : public std::exception
{
    public:
        virtual const char *what() const throw();
};

class WrongValue : public std::exception
{
    public:
        virtual const char *what() const throw();
};

#endif