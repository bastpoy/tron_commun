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
    std::cout << "je suis dans le char" << std::endl;
    std::cout << "char: " << input << std::endl;
    std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
    std::cout << "float: " << static_cast<float>(input[0]) << std::endl;
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
        std::cout << "float: " << static_cast<float>(number) << std::endl;
    if(number == HUGE_VAL || number == -HUGE_VAL)
        std::cout << "double: overflow" << std::endl;
    else
        std::cout << "double: " << number << std::endl;
    std::cout << "je suis dans le int" << std::endl;
}

void doFloat(std::string input)
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
        std::cout << "float: " << number << std::endl;
    std::cout << "double: " << static_cast<double>(number) << std::endl;        
    std::cout << "je suis dans le float" << std::endl;    
}

void doDouble(std::string input)
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
        std::cout << "float: " << static_cast<float>(number) << std::endl;
    if(number == HUGE_VAL || number == -HUGE_VAL)
        std::cout << "double: overflow" << std::endl;
    else
        std::cout << "double: " << number << std::endl;
    std::cout << "Je suis dans le double" << std::endl;
}

void ScalarConverter::convert(std::string input)
{
    if(isChar(input))
        doChar(input);
    else if(isInt(input))
        doInt(input);
    else if(isFloat(input))
        doFloat(input);
    else if(isDouble(input))
        doDouble(input);
    else
        std::cout << "Impossible convertion" << std::endl;
}

//detect le type
