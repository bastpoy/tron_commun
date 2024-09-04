#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::~BitcoinExchange()
{}

// FUNCTIONS

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDate(std::string &line)
{
    int year = atoi(line.substr(0, 4).c_str());
    int month = atoi(line.substr(5, 2).c_str());
    int day = atoi(line.substr(8, 2).c_str());

    if(month > 12 || month < 0)
        return false;
    
    int dayofmonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(month == 2 && isLeapYear(year))
    {
        dayofmonth[1] = 29;
    }
    return day > 0 && day <= dayofmonth[month - 1];
}

bool positionCharacter(std::string &line)
{
    if(line[4] == '-' && line[7] == '-' && line[10] == ' ')
    {
        for(size_t i = 0; i < line.length(); i++)
        {
            if(!isdigit(line[i]) && i != 4 && i != 7 && i != 10)
            {
                return (false);
            }
        }
    }
    else
        return (false);
    return (true);
}

float BitcoinExchange::check_value(std::string line)
{
    size_t length;
    int comma = 0;

    length = line.length();
    if(length < 14 || line[12] != ' ')
        throw WrongValue();
    line = line.substr(13, line.length() - 12);
    for(size_t i = 0; i < line.length(); i++)
    {
        if(line[i] == '.')
        {
            comma++;
            if(comma > 1)
                throw WrongValue();
        }
        else if(!isdigit(line[i]) && line[i])
        {
            throw WrongValue();
        }
    }
    double number = strtod(line.c_str(), NULL);
    if(number > 1000)
        throw WrongValue();
    return static_cast<float>(number);
}

void BitcoinExchange::check_date(std::ifstream &fd)
{
    std::string line;
    size_t pos;
    size_t i = 0;

    while(getline(fd, line))
    {
        if(i == 0 && line != "date | value")
            throw FirstLineError();
        if(i == 0)
        {
            i++;
            continue;
        }
        pos = line.find("|");
        if(pos != 11)
            throw WrongDateFormat();
        float value = check_value(line);
        line = line.substr(0, pos);
        if(line.length() != 11 || !positionCharacter(line) || !isValidDate(line))
            throw WrongDateFormat();
        // _keypair.insert(std::make_pair(line.substr(0, 10), value));
        dateInData(line.substr(0, 10), value);
        // std::cout << line << "-" << std::endl;
        i++;
    }
    // for (std::multimap<std::string, float>::iterator it = _keypair.begin(); it != _keypair.end(); ++it) {
    //     std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    // }
}

void BitcoinExchange::fillDate(void)
{
    std::ifstream data("data.csv");
    std::string line;
    std::string date;
    float value;

    getline(data, line);
    if(data.is_open())
    {
        while(getline(data, line))
        {
            date = line.substr(0, 10);
            value = std::strtof(line.substr(11, line.length() - 11).c_str(), NULL);
            _keypair.insert(std::make_pair(date,value));
        }
    }
    else
        throw CantOpeningFile();
}

void printLine(std::multimap<std::string, float>::iterator itData, std::string date, float value)
{
    std::cout << date <<  " => " << value << " = " << itData->second * value << std::endl;
}

void BitcoinExchange::dateInData(std::string date, float value)
{
    std::multimap<std::string, float>::iterator iterator;
    iterator = _keypair.lower_bound(date);
    if(iterator == _keypair.begin())
    {
        std::cout << std::endl << "inside prev" << std::endl;
        printLine(iterator, date, value);
    }
    else if(iterator == _keypair.end())
    {
        --iterator;
        std::cout << std::endl << "inside end" << std::endl;
        printLine(iterator, date, value);
    }
    else if(iterator->first == date)
    {
        std::cout << std::endl << "inside equal" << std::endl;
        printLine(iterator, date, value);
    }
    else
    {
        std::multimap<std::string, float>::iterator prevIterator = iterator;
        --prevIterator;
        if(iterator->first.compare(date) < date.compare(prevIterator->first))
        {
            std::cout << std::endl << "current " << iterator->first << std::endl;
            printLine(iterator, date, value);
        }
        else
        {
            std::cout << std::endl << "current " << prevIterator->first << std::endl;
            printLine(prevIterator, date, value);
        }
    }
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
const char *FirstLineError::what() const throw()
{
    return "First line not equal to: date | value";
}
const char *WrongValue::what() const throw()
{
    return "Wrong value";
}