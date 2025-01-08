#include "Form.hpp"

Form::Form() : _name("Default"), _isSigned(false), _gradesign(50), _gradeexec(50)
{}

Form::~Form()
{}

Form::Form(const std::string name, const int gradesign, const int gradeexec) : _name(name), _isSigned(false), _gradesign(gradesign), _gradeexec(gradeexec)
{
    if(gradesign < 1 || gradeexec < 1)
        throw GradeTooHighException();
    else if(gradesign > 150 || gradeexec > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &copy) : _name(copy._name), _gradesign(copy._gradesign), _gradeexec(copy._gradeexec)
{
    *this = copy;
}

Form &Form::operator=(const Form &copy)
{
    if(this != &copy)
    {
        this->_isSigned = copy._isSigned;
    }
    return *this;
}

// MEMBER FUNCTION

bool Form::get_signed() const
{
    return this->_isSigned;
}

const std::string Form::get_name() const
{
    return this->_name;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if(this->_gradesign == true)
        return;
    if(bureaucrat.getGrade() <= this->_gradesign)
        this->_isSigned = true;
    else
        throw GradeTooLowException();
}

int Form::get_gradesign() const
{
    return this->_gradesign;
}
int Form::get_gradeexec() const
{
    return this->_gradeexec;
}

//EXCEPTION

const char* Form::GradeTooLowException::what() const throw()
{
    return("grade too low");
}

const char* Form::GradeTooHighException::what() const throw()
{
    return("grade too high");
}

// OVERLOAD << OPERATOR

std::ostream& operator<<(std::ostream& os, const Form& f)
{
    os << f.get_name() << ", Form gradeSign " << f.get_gradesign()
    << ", Form gradeexec " << f.get_gradeexec()
    << ", Form is signed " << f.get_signed() << std::endl;
    return os; 
}