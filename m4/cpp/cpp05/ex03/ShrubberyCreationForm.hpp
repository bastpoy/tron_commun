#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm();
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(ShrubberyCreationForm &copy);
        ShrubberyCreationForm &operator=(ShrubberyCreationForm &copy);
        ShrubberyCreationForm(std::string target);

        std::string get_target() const;
        void execute(Bureaucrat const &executor) const;

    private:
        std::string _target;
};

#endif