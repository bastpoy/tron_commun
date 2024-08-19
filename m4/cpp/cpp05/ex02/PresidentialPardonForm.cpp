#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): Form("Presidential", 25, 5), _target("Default")
{}

PresidentialPardonForm::PresidentialPardonForm(std::string target): Form("Presidential", 25, 5), _target(target)
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
{
    *this = copy;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
    if(this != &copy)
        this->_target = copy.get_target();
    return *this;
}

// MEMBER FUNCTIONS

std::string PresidentialPardonForm::get_target() const
{
    return this->_target;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor)
{
    if(this->get_signed() == true)
        throw FormAlreadySign();
    else if(executor.getGrade() > this->get_gradeexec())
        throw GradeTooLowException();
    std::cout << this->get_target() << 
        " has been pardoned by Zaphod Beeblerox" << std::endl;
}