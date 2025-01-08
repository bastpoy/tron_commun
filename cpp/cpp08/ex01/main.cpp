#include "Span.hpp"

int main()
{
    try
    {
        Span sp = Span(3);
        Span sp1(2);

        sp.addNumber(6);
        sp.addNumber(12);
        sp.addNumber(-20);
        // sp.addNumber(9);
        // sp.addNumber(11);

        sp1 = sp;
        sp.printSpan();

        std::cout << "max " << sp.longestSpan() << std::endl;
        std::cout << "min " << sp.shortestSpan() << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::vector<int> re(10000);
        std::srand(time(NULL));
        std::generate(re.begin(), re.end(), std::rand);

        Span la(10000);
        la.addMultipleNumbers(re.begin(), re.end());
        std::cout << la.longestSpan() << std::endl;
        std::cout << la.shortestSpan() << std::endl;
        // la.printSpan();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}