#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    public:
        Form();
        ~Form();
        Form(const std::string name, const int gradesign, const int gradeexec);
        Form(const Form &copy);
        Form &operator=(const Form &copy);
        
        class GradeTooLowException : public std::exception{
            public:
                virtual const char* what() const throw();
        };
        class GradeTooHighException : public std::exception{
            public:
                virtual const char* what() const throw();
        };

        const std::string get_name() const ;
        bool get_signed() const;
        int get_gradesign() const;
        int get_gradeexec() const;
        void beSigned(Bureaucrat &bureaucrat);
        
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradesign;
        const int _gradeexec;
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif