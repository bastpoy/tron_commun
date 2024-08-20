#include "AForm.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _gradesign(50), _gradeexec(50)
{}

AForm::~AForm()
{}

AForm::AForm(const std::string name, const int gradesign, const int gradeexec) : _name(name), _isSigned(false), _gradesign(gradesign), _gradeexec(gradeexec)
{
    if(gradesign < 1 || gradeexec < 1)
        throw GradeTooHighException();
    else if(gradesign > 150 || gradeexec > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &copy) : _name(copy._name), _gradesign(copy._gradesign), _gradeexec(copy._gradeexec)
{
    *this = copy;
}

AForm &AForm::operator=(const AForm &copy)
{
    if(this != &copy)
    {
        this->_isSigned = copy._isSigned;
    }
    return *this;
}

// MEMBER FUNCTION

bool AForm::get_signed() const
{
    return this->_isSigned;
}

const std::string AForm::get_name() const
{
    return this->_name;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if(this->_gradesign == true)
        return;
    if(bureaucrat.getGrade() <= this->_gradesign)
        this->_isSigned = true;
    else
        throw GradeTooLowException();
}

int AForm::get_gradesign() const
{
    return this->_gradesign;
}
int AForm::get_gradeexec() const
{
    return this->_gradeexec;
}

//EXCEPTION

const char* AForm::GradeTooLowException::what() const throw()
{
    return("grade too low");
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return("grade too high");
}

const char* AForm::FormAlreadySign::what() const throw()
{
    return("Form already sign");
}

const char* AForm::ErrorOpeningFile::what() const throw()
{
    return("Error opening file");
}

// OVERLOAD << OPERATOR

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
    os << f.get_name() << ", Form gradeSign " << f.get_gradesign()
    << ", Form gradeexec " << f.get_gradeexec()
    << ", Form is signed " << f.get_signed() << std::endl;
    return os; 
}