#include "MutantStack.hpp"

int main(void)
{
    MutantStack<int> salut;
    (void)salut;
    std::cout << "re" << std::endl;
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
}