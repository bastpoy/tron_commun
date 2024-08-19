#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
    try
    {
        Bureaucrat a("a", 1);
        Bureaucrat b("b", 150);
        // AForm f = ShrubberyCreationForm("Russia");
        // AForm *g = new ShrubberyCreationForm("Russia");
        ShrubberyCreationForm c("Russia");
        c.execute(a);
        // Bureaucrat c("c", 151);
        // Bureaucrat d("d", 0);

        // std::cout << f;
        std::cout << a;
        std::cout << b;
        // b.signForm(f);
        // a.signForm(f);
        // b.decrement();
        // a.increment();
    }
    catch (std::exception & e)
    {
        std::cout << "error: " << e.what() << std::endl;
    }
}