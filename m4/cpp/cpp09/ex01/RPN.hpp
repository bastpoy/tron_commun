#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

class RPN
{
    private:
        std::stack<double> numbers;

    public:
        RPN();
        ~RPN();
        RPN(const RPN &copy);
        RPN &operator=(const RPN &copy);

        void printRPN();
        void algorithm(std::string input);
        bool do_maths(int copy, std::string input, size_t index);
};

bool check_input(std::string input);

#endif