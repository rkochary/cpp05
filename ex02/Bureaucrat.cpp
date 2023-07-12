#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("")
{
    _grade = 150;
    std::cout << "Default Constructor called for Bureaucrat" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade):_name(name)
{
    if(grade > 150)
        throw GradeTooLowException();
    else if (grade < 1)
      throw GradeTooHighException();  
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
    return *this;
}

void Bureaucrat::increment()
{
    this->_grade--;
    if(this->_grade < 1)
        throw GradeTooHighException();
}

void Bureaucrat::decrement()
{
    this->_grade++;
    if(this->_grade > 150)
        throw GradeTooLowException();
}


Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor called for Bureaucrat" << std::endl;
}

const  std::string& Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high" ;
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
} 

void Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << "'" << this->getName() << "'" << " signed to " << form.getName() << std::endl;
    }
    catch(AForm::GradeTooLowException& e)
    {
        std::cout << "!!#" << this->getName() << "!!#"
        << " couldn't sign to "
        << form.getName()
        << " because " << e.what()
        << std::endl;
    }
}

std::ostream& operator<<(std::ostream& cout, const Bureaucrat& obj)
{
    cout << obj.getName() << "'s bureaucrat grade is " << obj.getGrade();
    return (cout);
}