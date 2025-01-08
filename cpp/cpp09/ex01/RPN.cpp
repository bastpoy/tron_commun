#include "RPN.hpp"

RPN::RPN()
{}

RPN::~RPN()
{}

RPN::RPN(const RPN &copy)
{
    *this = copy;
}

RPN &RPN::operator=(const RPN &copy)
{
    if(this != &copy)
    {
        this->numbers = copy.numbers;
    }
    return (*this);
}

void RPN::printRPN()
{
    std::stack<double> copy = this->numbers;
    while(!copy.empty())
    {
        std::cout << copy.top() << std::endl;
        copy.pop();
    }
}

bool check_space(char caracter, int index)
{
    if(index % 2 == 1 && caracter != ' ')
        return (false);
    return (true);
}

bool RPN::do_maths(int copy, std::string input, size_t index)
{
    double result = 0;
    if(input[index] == '+')
    {
        result = this->numbers.top() + copy;
    }
    else if(input[index] == '-')
    {
        result = this->numbers.top() - copy;
    }
    else if (input[index] == '/')
    {
        result = this->numbers.top() / copy;
    }
    else if (input[index] == '*')
    {
        result = this->numbers.top() * copy;
    }
    // std::cout << "result: " << result << " copy: " << copy << " top number: " << this->numbers.top() << std::endl;
    this->numbers.pop();
    this->numbers.push(result);
    return(true);
}

void RPN::algorithm(std::string input)
{
    int number = 0;
    double copy;
    for(size_t i = 0 ; i < input.length(); i++)
    {
        number = input[i] - '0';
        if((number >= 0 && number <= 9) && i % 2 == 0 && input.length() - 1)
        {
            this->numbers.push(static_cast<double>(number));
        }
        else if (input[i] == ' ' && i % 2 == 1 && i != input.length() - 1)
        {
            continue;
        }
        else if((input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') && 
            i % 2 == 0 && this->numbers.size() >= 2)
        {
            copy = this->numbers.top();
            this->numbers.pop();
            this->do_maths(copy, input, i);
        }
        else
        {
            std::cout << "wrong input" << std::endl;
            return;
        }
    }
    if(this->numbers.size() > 1)
        std::cout << "wrong input" << std::endl;
    else
        std::cout << this->numbers.top() << std::endl;
}

