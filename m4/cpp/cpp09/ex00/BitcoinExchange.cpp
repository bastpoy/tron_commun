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
    if(day > 0 && day <= dayofmonth[month - 1])
        return (1);
    else
    {
        std::cout << "Not a valid date: " << line << std::endl;
        return (0);
    }
    return day > 0 && day <= dayofmonth[month - 1];
}

bool positionCharacter(std::string &line)
{
    if(line.length() != 11 )
    {
        std::cout << "Not a valid date: " << line << std::endl;
        return (false);        
    }
    if(line[4] == '-' && line[7] == '-' && line[10] == ' ')
    {
        for(size_t i = 0; i < line.length(); i++)
        {
            if(!isdigit(line[i]) && i != 4 && i != 7 && i != 10)
            {
                std::cout << "Caracter inside date " << line << std::endl;
                return (false);
            }
        }
    }
    else
    {
        std::cout << "Not a valid date: " << line << std::endl;
        return (false);
    }
    return (true);
}

bool BitcoinExchange::check_value(std::string line, float &value)
{
    size_t length;
    int comma = 0;

    length = line.length();
    if(length < 14 || line[12] != ' ')
    {
        std::cout << "Error: bad date configuration: " << line << std::endl;
        return (0);
    }
    line = line.substr(13, line.length() - 12);
    for(size_t i = 0; i < line.length(); i++)
    {
        if(line[i] == '.')
        {
            comma++;
            if(comma > 1)
            {
                std::cout << "Two much . inside the value: " << line << std::endl;
                return (0);
            }
        }
        else if(!isdigit(line[i]) && line[i])
        {
            std::cout << "Error: bad date configuration: " << line << std::endl;
            return (0);
        }
    }
    double number = strtod(line.c_str(), NULL);
    if(number > 1000)
    {
        std::cout << "Error two large number." << std::endl;
        return (0);
    }
    value =  static_cast<float>(number);
    return(1);
}

void BitcoinExchange::check_date(std::ifstream &fd)
{
    std::string line;
    size_t pos;
    size_t i = 0;
    float value;

    while(getline(fd, line))
    {
        if(i == 0 && line != "date | value")
        {
            std::cout << "First line not equal to: date | value" << std::endl;
            return;
        }
        if(i == 0)
        {
            i++;
            continue;
        }
        pos = line.find("|");
        if(pos != 11)
        {
            std::cout << "Error: bad line configuration: " << line << std::endl;
            continue;
        }
        if(!check_value(line, value))
            continue;
        line = line.substr(0, pos);
        if(!positionCharacter(line) || !isValidDate(line))
            continue;
        dateInData(line.substr(0, 10), value);
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

time_t parseDate(const std::string &date) {
    struct tm tm = {};  // Initialise tous les champs à 0
    // Parse la date en format "YYYY-MM-DD"
    if (strptime(date.c_str(), "%Y-%m-%d", &tm) == NULL) {
        std::cerr << "Erreur lors de l'analyse de la date : " << date << std::endl;
        return -1; // Retourne une valeur d'erreur si l'analyse échoue
    }
    return mktime(&tm); 
}

void BitcoinExchange::dateInData(std::string date, float value)
{
    std::multimap<std::string, float>::iterator iterator;
    iterator = _keypair.lower_bound(date);
    if(iterator == _keypair.begin())
        printLine(iterator, date, value);
    else if(iterator == _keypair.end())
    {
        --iterator;
        printLine(iterator, date, value);
    }
    else if(iterator->first == date)
        printLine(iterator, date, value);
    else
    {
        std::multimap<std::string, float>::iterator prevIterator = iterator;
        --prevIterator;
        
        time_t givenDate = parseDate(date);
        time_t nextDate = parseDate(iterator->first);
        time_t prevDate = parseDate(prevIterator->first);


        // Calculate absolute differences
        double diffNext = difftime(nextDate, givenDate);
        double diffPrev = difftime(prevDate, givenDate);

        if(std::abs(diffNext) < std::abs(diffPrev))
            printLine(iterator, date, value);
        else
            printLine(prevIterator, date, value);
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