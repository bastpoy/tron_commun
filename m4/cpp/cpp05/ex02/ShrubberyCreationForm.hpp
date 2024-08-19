#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public Form
{
    public:
        ShrubberyCreationForm();
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(ShrubberyCreationForm &copy);
        ShrubberyCreationForm &operator=(ShrubberyCreationForm &copy);
        ShrubberyCreationForm(std::string target);

        std::string get_target() const;
        void execute(Bureaucrat &executor) const;

    private:
        std::string _target;
};

#endif