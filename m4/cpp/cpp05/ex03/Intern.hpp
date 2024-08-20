#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define MAX_FORM 10

class Intern
{
    public:
        Intern();
        ~Intern();
        Intern(const Intern &copy);
        Intern &operator=(const Intern &copy);
        AForm *makeForm(const std::string formName, const std::string targetForm);
        AForm *shruberryForm(const std::string &targetForm);
        AForm *robotomyForm(const std::string &targetForm);
        AForm *presidentialForm(const std::string &targetForm);

        class WrongType : public std::exception{
            public:
                virtual const char* what() const throw();
        };

};

#endif