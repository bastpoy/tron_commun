#include "Span.hpp"

int main()
{
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    sp.printSpan();
    // std::cout << sp.shortestSpan() << std::endl;
    std::cout << "le longest " << sp.longestSpan() << std::endl;

    return 0;
}