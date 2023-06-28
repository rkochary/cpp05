#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
        const std::string _name;
        bool _isSigned;
        const int _reqSignIt;
        const int _reqExequteIt;
    public:
        Form();
        Form(std::string name,int sign,int exequte);
        Form(const Form &obj);
        Form & operator=(const Form &obj);//
        ~Form();
        const std::string &getName() const;
        const int &getReqSignIt() const;
        const int &getReqExequteIt() const;
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
        void beSigned(Bureaucrat &obj);
};

 std::ostream& operator<<(std::ostream& cout, const Form& obj);

#endif