#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
    try
    {
        Bureaucrat a("a", 1);
        Bureaucrat b("b", 150);
        // AForm f = ShrubberyCreationForm("Russia");
        // AForm *g = new ShrubberyCreationForm("Russia");
        ShrubberyCreationForm c("Russia");
        PresidentialPardonForm d("coree");
        RobotomyRequestForm e("Chine");

        c.execute(a);
        d.execute(a);
        d.execute(a);
        // d.execute(b);
        e.execute(a); // once in two change output
        e.execute(a); // once in two change output
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