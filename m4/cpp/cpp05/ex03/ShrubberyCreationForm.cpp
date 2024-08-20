#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Shrubbery", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery", 145, 137), _target("default")
{}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &copy) : AForm(copy)
{
    *this = copy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &copy)
{
    if(this != &copy)
        this->_target = copy.get_target();
    return *this;
}

//MEMBER FUNCTION

std::string ShrubberyCreationForm::get_target() const
{
    return this->_target;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if(this->get_signed() == true)
        throw FormAlreadySign();
    else if(executor.getGrade() > this->get_gradeexec())
        throw GradeTooLowException();
    std::ofstream myfile((this->get_target() + "_shrubbery").c_str());

    std::string tree = 
    "        *\n"
    "       ***\n"
    "      *****\n"
    "     *******\n"
    "    *********\n"
    "   ***********\n"
    "  *************\n"
    " ***************\n"
    "       |||\n"
    "       |||\n";
    if (myfile.is_open()) 
    {
        myfile << tree << std::endl;
    }
    else
        throw ErrorOpeningFile();
}