#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
        const std::string _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat &obj);
        Bureaucrat & operator=(const Bureaucrat &obj);
        ~Bureaucrat();
        const std::string &getName() const;
        int getGrade() const;
        void increment();
        void decrement();
        void signForm(Form &form);
        class GradeTooHighException : public std::exception 
        {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception 
        {
            public:
                virtual const char* what() const throw();
        };
};
    std::ostream& operator<<(std::ostream& cout, const Bureaucrat& obj);


#endif