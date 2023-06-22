#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("")
{
    _grade = 150;
    std::cout << "Default Constructor called for Bureaucrat" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade):_name(name)
{
    this->_grade = grade;

}

Bureaucrat::Bureaucrat(const Bureaucrat &obj):_name(obj._name)
{
    this->_grade = obj._grade;
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat &obj)
{
    if(this != &obj)
    {
        this->_grade = obj._grade;
    }
}

void Bureaucrat::increment()
{
    this->_grade--;
    if(this->_grade < 1)
        throw GradeTooLowException();
}

void Bureaucrat::decrement()
{
    this->_grade++;
    if(this->_grade > 150)
        throw GradeTooHighException();
}


Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor called for Bureaucrat" << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high" ;
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
} 