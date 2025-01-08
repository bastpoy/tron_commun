#include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern &copy)
{
    *this = copy;
}

Intern &Intern::operator=(const Intern &copy)
{
    (void)copy;
    return (*this);
}

AForm *Intern::shruberryForm(const std::string &targetForm)
{
    return new ShrubberyCreationForm(targetForm);
}

AForm *Intern::robotomyForm(const std::string &targetForm)
{
    return new RobotomyRequestForm(targetForm);
}

AForm *Intern::presidentialForm(const std::string &targetForm)
{
    return new PresidentialPardonForm(targetForm);
}

AForm *Intern::makeForm(const std::string formName, const std::string targetForm)
{
    std::string formType[3] = {"Shrubbery", "Robotomy", "Presidential"};
    AForm *(Intern::* intern[])(const std::string &targetForm) = 
        {&Intern::shruberryForm, &Intern::robotomyForm, &Intern::presidentialForm};
    
    for(int i = 0; i < 3; i++)
    {
        if(formType[i] == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*(intern[i]))(targetForm);
        }
    }
    throw Intern::WrongType();
}

// EXCEPTION

const char* Intern::WrongType::what() const throw()
{
    return("Wrong type of form");
}