#ifndef AFORM_HPP
#define AFORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
        const std::string _name;
        bool _isSigned;
        const int _reqSignIt;
        const int _reqExequteIt;
    public:
        AForm();
        AForm(std::string name,int sign,int exequte);
        AForm(const AForm &obj);
        AForm & operator=(const AForm &obj);//
        virtual ~AForm();
        const std::string &getName() const;
        const int &getReqSignIt() const;
        const int &getReqExequteIt() const;
        bool getIsSigned() const;
        virtual void execute(Bureaucrat const & executor) const = 0;
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
                class SignedSuccessException: public std::exception
        {
            public:
                const char * what() const throw();
        };
        void beSigned(Bureaucrat &obj);
};

 std::ostream& operator<<(std::ostream& cout, const AForm& obj);

#endif