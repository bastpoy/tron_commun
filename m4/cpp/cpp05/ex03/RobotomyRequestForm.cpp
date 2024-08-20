#include "RobotomyRequestForm.hpp"

static int robotomytenta = 0;

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45), _target("default")
{}
RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robotomy", 72, 45), _target(target)
{}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
{
    *this = copy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
    if(this != &copy)
        this->_target = copy.get_target();
    return *this;
}

// MEMBER FUNCTIONS

std::string RobotomyRequestForm::get_target() const
{
    return this->_target;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if(executor.getGrade() > this->get_gradeexec())
        throw GradeTooLowException();
    else if(this->get_signed() == true)
        throw FormAlreadySign();
    else if(robotomytenta % 2 == 0)
    {
        std::cout << "**Drilling noises**  " << 
        this->_target << " has been robotomized" << std::endl;
        robotomytenta++;
    }
    else
    {
        std::cout << "**Drilling noises**  " << 
        this->_target << " robotomy failed" << std::endl;    
    }
}