#ifndef INTERN_HPP
#define INTERN_HPP
#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


class Intern
{
    public:
        Intern();
        //Intern();
        //Intern(const Intern &obj);
        Intern &operator=(const Intern &obj);
        ~Intern();
        AForm* makeForm(const std::string &name,const std::string &target);
        class Exception : public std::exception 
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif