#include "MutantStack.hpp"

int main(void)
{
    MutantStack<int> salut;

    salut.push(12);
    salut.push(13);
    salut.push(15);

    std::cout << salut.top() << std::endl;
    std::cout << *salut.begin() << std::endl;

    salut.pop();

    std::cout << salut.empty() << std::endl;

    MutantStack<int>::iterator it = salut.begin();
    MutantStack<int>::iterator ite = salut.end();
    
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(salut);

    std::cout << s.top() << std::endl;
    std::cout << "The size: "<< s.size() << std::endl;
}

// int main(void)
// {
//     MutantStack<std::string> salut;

//     salut.push("mec");
//     salut.push("ca va");
//     salut.push("ouais");

//     std::cout << salut.top() << std::endl;
//     std::cout << *salut.begin() << std::endl;

//     salut.pop();

//     std::cout << salut.empty() << std::endl;

//     MutantStack<std::string>::iterator it = salut.begin();
//     MutantStack<std::string>::iterator ite = salut.end();
    
//     ++it;
//     --it;
//     while (it != ite)
//     {
//         std::cout << *it << std::endl;
//         ++it;
//     }
//     std::stack<std::string> s(salut);

//     std::cout << s.top() << std::endl;
//     std::cout << "The size: "<< s.size() << std::endl;
// }