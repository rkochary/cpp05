#include "Form.hpp"

Form::Form() : _name("") ,_isSigned(false), _reqSignIt(1),_reqExequteIt(150)
{

}

Form::Form(std::string name,int sign,int exequte) : _name(name),_reqSignIt(sign),_reqExequteIt(exequte)
{
    if(sign < 1 || exequte < 1)
    {
        throw GradeTooLowException();
    }
    else if (sign > 150 || exequte > 150)
    {
        throw GradeTooHighException();
    }
}

Form::Form(const Form &obj) : _name(obj._name) ,_isSigned(obj._isSigned), _reqSignIt(obj._reqSignIt),_reqExequteIt(obj._reqExequteIt)
{

}

Form & Form::operator=(const Form &obj)
{
    if(this != &obj)
    {
        this->_isSigned = obj._isSigned;  
    }
    return *this;
}

const std::string &Form::getName() const
{
    return _name;
}

const int &Form::getReqExequteIt() const
{
    return _reqExequteIt;
}

const int &Form::getReqSignIt() const
{
    return _reqSignIt;
}

Form::~Form()
{

}



const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high" ;
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

void Form::beSigned(Bureaucrat &obj)//anel
{
    if(obj.getGrade() > this-> getReqSignIt())
        throw GradeTooLowException();
    else
    {
        std::cout << obj.getName() << " signed " << this->getName() << std::endl;
        _isSigned = true;
    }

}

bool Form::getIsSigned() const
{
    return _isSigned;
}

std::ostream& operator<<(std::ostream& cout, const Form& obj)
{
    cout << "Forms name is " << obj.getName()
    << " reqSignIt is " << obj.getReqSignIt()
    << " reqExequteIt " << obj.getReqExequteIt() << std::endl;
    if(obj.getIsSigned())
        cout << "Signatured!\n";
    else
        cout << "Unsignatured!\n";
    return cout;

} 

