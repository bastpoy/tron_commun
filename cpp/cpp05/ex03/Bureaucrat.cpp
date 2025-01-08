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

Bureaucrat::Bureaucrat(const Bureaucrat& copy): _name(copy._name)
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

void Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
        if(form.get_signed())
            std::cout << this->getName() << " signed " << form.get_name() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << this->getName() << " couldn't sign " << form.get_name() << " because " << e.what() <<  std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form)
{
    try
    {
        form.execute(*this);
        if(form.get_signed())
            std::cout << this->_name << " executed " << form.get_name() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    
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