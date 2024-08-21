#include "ScalarConverter.hpp"
#include <stdlib.h>
#include <climits>
#include <cfloat>
#include <cstdlib>
#include <cmath>

bool isChar(std::string input)
{
    if(!isdigit(input[0]) && input.length() == 1)
    {
        if(static_cast<int>(input[0]) < 33 || static_cast<int>(input[0]) > 126)
            return (false);
        return (true);
    }
    return false;
}

bool isInt(std::string input)
{
    if(input[0] != '-' && input[0] != '+' && !isdigit(input[0]))
        return false;
    for(size_t i = 0; i < input.length(); i++)
    {
        if(!isdigit(input[i]) && i != 0)
            return (false);
    }
    return (true);
}

bool isFloat(std::string input)
{
    int comma = 0;
    int f = 0;
    if(input[0] != '-' && input[0] != '+' && !isdigit(input[0]))
        return (false);
    for(size_t i = 0; i < input.length(); i++)
    {
        if(input[i] == '.')
        {
            comma++;
            if(comma > 1)
                return (false);
        }
        if(input[i] == 'f' && i != input.length() - 1)
            return (false);
        if(!isdigit(input[i]) && input[i] != 'f' && input[i] != '.')
            return (false);
        if(!isdigit(input[i]) && input[i] == 'f')
            f++;
        if(f > 1)
            return(false);
    }
    if(input.length() - comma - f > 7)
        return false;
    return (true);
}

bool isDouble(std::string input)
{
    int comma = 0;
    if(input[0] != '-' && input[0] != '+' && !isdigit(input[0]))
        return (false);
    for(size_t i = 0; i < input.length(); i++)
    {
        if(input[i] == '.')
        {
            comma++;
            if(comma > 1)
                return (false);
        }
        if(!isdigit(input[i]) && input[i] != '.')
            return (false);
    }
    if(input.length() - comma > 16)
        return false;
    return (true);
}

void doChar(std::string input)
{
    std::cout << "char: " << input << std::endl;
    std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
    std::cout << "float: " << static_cast<float>(input[0]);
    if(input.find('.') != std::string::npos)
        std::cout << "f";
    std::cout << std::endl;
    std::cout << "double: " << static_cast<double>(input[0]) << std::endl;
}

void doInt(std::string input)
{
    double number = strtod(input.c_str(), NULL);

    if(input.find('.') == std::string::npos && number > 32 && number < 127)
        std::cout << "char: '" << static_cast<char>(number) << "'" << std::endl;
    else
        std::cout << "char: impossible" << std::endl;
    if(number > static_cast<double>(INT_MAX) || number < static_cast<double>(INT_MIN))
        std::cout << "int: overflow" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(number) << std::endl;
    if(number > static_cast<double>(FLT_MAX) || number < static_cast<double>(FLT_MIN))
        std::cout << "float: overflow" << std::endl;
    else
    {
        std::cout << "float: " << static_cast<float>(number);
        if(input.find('.') != std::string::npos)
            std::cout << "f";
        std::cout << std::endl;
    }
    if(number == HUGE_VAL || number == -HUGE_VAL)
        std::cout << "double: overflow" << std::endl;
    else
        std::cout << "double: " << number << std::endl;
}

void doFloat(std::string input, bool &isDiff)
{
    double number = strtod(input.c_str(), NULL);
    
    if(input.find('.') == std::string::npos && number > 32 && number < 127)
        std::cout << "char: '" << static_cast<char>(number) << "'" << std::endl;
    else
        std::cout << "char: impossible" << std::endl;
    if(number > static_cast<double>(INT_MAX) || number < static_cast<double>(INT_MIN) || std::isnan(number))
        std::cout << "int: overflow" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(number) << std::endl;        
    if((number > static_cast<double>(FLT_MAX) || number < static_cast<double>(FLT_MIN)) && !isDiff)
        std::cout << "float: overflow" << std::endl;
    else
    {
        std::cout << "float: " << static_cast<float>(number);
        if(input.find('.') != std::string::npos || isDiff)
            std::cout << "f";
        std::cout << std::endl;
    }
    std::cout << "double: " << static_cast<double>(number) << std::endl;        
}

void doDouble(std::string input, bool &isDiff)
{
    double number = strtod(input.c_str(), NULL);

    if(input.find('.') == std::string::npos && number > 32 && number < 127)
        std::cout << "char: '" << static_cast<char>(number) << "'" << std::endl;
    else
        std::cout << "char: impossible" << std::endl;
    if(number > static_cast<double>(INT_MAX) || number < static_cast<double>(INT_MIN) || std::isnan(number))
        std::cout << "int: overflow" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(number) << std::endl;
    if((number > static_cast<double>(FLT_MAX) || number < static_cast<double>(FLT_MIN)) && isDiff)
        std::cout << "float: overflow" << std::endl;
    else
    {
        std::cout << "float: " << static_cast<float>(number);
        if(input.find('.') != std::string::npos || isDiff)
            std::cout << "f";
        std::cout << std::endl;
    }
    if((number == HUGE_VAL || number == -HUGE_VAL) && !isDiff)
        std::cout << "double: overflow" << std::endl;
    else
        std::cout << "double: " << number << std::endl;
}

bool isDiffFloat(std::string input, bool &isdiff)
{
    if(input == "-inff" || input == "+inff" || input == "nanf")
    {
        isdiff = true;
        return (true);
    }
    return (false);
}

bool isDiffDouble(std::string input, bool &isdiff)
{
    if(input == "-inf" || input == "+inf" || input == "nan")
    {
        isdiff = true;
        return (true);
    }
    return (false);
}

void ScalarConverter::convert(std::string input)
{
    bool isDiff = false;

    if(isChar(input))
        doChar(input);
    else if(isInt(input))
        doInt(input);
    else if(isFloat(input) || isDiffFloat(input, isDiff))
        doFloat(input, isDiff);
    else if(isDouble(input) || isDiffDouble(input, isDiff))
        doDouble(input, isDiff);
    else
        std::cout << "Impossible convertion of input number" << std::endl;
}
