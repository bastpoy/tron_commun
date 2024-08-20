#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("default"), _grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name)
{
    if(grade > 150)
        throw GradeTooLowException();
    else if(grade < 1)
        throw GradeTooHighException();
    this->_grade = grade;
}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat::Bureaucrat(const Bureaucrat& copy)
{
    *this = copy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
    if(this != &copy)
    {
        this->_grade = copy.getGrade();
    }
    return(*this);
}

// MEMEBER FUNCTIONS

std::string const Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}

void Bureaucrat::decrement()
{
    if(this->_grade == 150)
        throw GradeTooLowException();
    this->_grade++;
}

void Bureaucrat::increment()
{
    if(this->_grade == 1)
        throw GradeTooHighException();
    this->_grade--;
}

// EXCEPTION

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return("grade too low");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return("grade too high");
}

// SURCHARGE OPERATEUR <<

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
    return os; 
}