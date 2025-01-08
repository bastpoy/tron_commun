#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    public:
        AForm();
        ~AForm();
        AForm(const std::string name, const int gradesign, const int gradeexec);
        AForm(const AForm &copy);
        AForm &operator=(const AForm &copy);
        
        class GradeTooLowException : public std::exception{
            public:
                virtual const char* what() const throw();
        };
        class GradeTooHighException : public std::exception{
            public:
                virtual const char* what() const throw();
        };

        class FormAlreadySign : public std::exception{
            public:
                virtual const char* what() const throw();
        };
        class ErrorOpeningFile : public std::exception{
            public:
                virtual const char* what() const throw();
        };

        const std::string get_name() const ;
        bool get_signed() const;
        int get_gradesign() const;
        int get_gradeexec() const;
        void beSigned(Bureaucrat &bureaucrat);
        virtual void execute(Bureaucrat const &bureaucrat) const = 0;

    private:
        const std::string _name;
        bool _isSigned;
        const int _gradesign;
        const int _gradeexec;
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif