#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat a("a", 1);
        Bureaucrat b("b", 150);
        // Bureaucrat c("c", 151);
        // Bureaucrat d("d", 0);

        std::cout << a;
        std::cout << b;

        // b.decrement();
        a.increment();        
    }
    catch (std::exception & e)
    {
        std::cout << "error: " << e.what() << std::endl;
    }
}