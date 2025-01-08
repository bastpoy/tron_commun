#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat a("a", 1);
        Bureaucrat b("b", 150);
        Form f("f", 50, 50);
        // Bureaucrat c("c", 151);
        // Bureaucrat d("d", 0);

        std::cout << f;
        std::cout << a;
        std::cout << b;
        b.signForm(f);
        a.signForm(f);
        // b.decrement();
        a.increment();
    }
    catch (std::exception & e)
    {
        std::cout << "error: " << e.what() << std::endl;
    }
}