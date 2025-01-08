#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
    try
    {
        Bureaucrat a("a", 1);
        Bureaucrat b("b", 150);
        Intern intern;
        // AForm f = ShrubberyCreationForm("Russia");
        // AForm *g = new ShrubberyCreationForm("Russia");
        ShrubberyCreationForm *d = (ShrubberyCreationForm*)intern.makeForm("Shrubbery", "cleshrubmagl");
        AForm *e = intern.makeForm("Robotomy", "clerobotmagl");
        AForm *g = intern.makeForm("Robotomy", "clerobotmagl");
        // RobotomyRequestForm *f = (RobotomyRequestForm*)intern.makeForm("fakeRobotomy", "clerobotmagl");

        d->execute(a);
        e->execute(a);
        g->execute(a);

        // e->execute(b);
        // f->execute(a);
        // Bureaucrat c("c", 151);
        // Bureaucrat d("d", 0);

        // std::cout << f;
        std::cout << a;
        std::cout << b;
        std::cout << *d;
        std::cout << *g;
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