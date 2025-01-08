#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
    public:
        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat& copy);
        Bureaucrat &operator=(const Bureaucrat& copy);
        std::string const getName() const;
        int getGrade() const;
        void signForm(Form &form);
        void decrement();
        void increment();
        
        class GradeTooLowException : public std::exception{
            public:
                virtual const char* what() const throw();
        };
        class GradeTooHighException : public std::exception{
            public:
                virtual const char* what() const throw();
        };

    private:
        const std::string _name;
        int _grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif