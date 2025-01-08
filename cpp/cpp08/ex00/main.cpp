#include <iostream>
#include "easyfind.hpp"

int main(void)
{
    try
    {
        std::vector<int> test;
        test.push_back(10);
        test.push_back(20);
        test.push_back(30);
        test.push_back(40);

        easyfind(test, 30);

        std::list<int> test1;
        test1.push_back(10);
        test1.push_back(20);
        test1.push_back(30);
        test1.push_back(40);

        easyfind(test1, 5);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}