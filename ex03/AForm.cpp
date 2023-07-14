#include "AForm.hpp"

AForm::AForm() : _name("") ,_isSigned(false), _reqSignIt(1),_reqExequteIt(150)
{

}

AForm::AForm(std::string name,int sign,int exequte) : _name(name),_reqSignIt(sign),_reqExequteIt(exequte)
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

AForm::AForm(const AForm &obj) : _name(obj._name) ,_isSigned(obj._isSigned), _reqSignIt(obj._reqSignIt),_reqExequteIt(obj._reqExequteIt)
{

}

AForm & AForm::operator=(const AForm &obj)
{
    if(this != &obj)
    {
        this->_isSigned = obj._isSigned;  
    }
    return *this;
}

const std::string &AForm::getName() const
{
    return _name;
}

const int &AForm::getReqExequteIt() const
{
    return _reqExequteIt;
}

const int &AForm::getReqSignIt() const
{
    return _reqSignIt;
}

AForm::~AForm()
{

}



const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high" ;
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

const char* AForm::SignedSuccessException::what() const throw()
{
    return "The form isn't signed!";
}

void AForm::beSigned(Bureaucrat &obj)//anel
{
    if(obj.getGrade() > this-> getReqSignIt())
        throw GradeTooLowException();
    else
    {
        std::cout << obj.getName() << " signed " << this->getName() << std::endl;
        _isSigned = true;
    }

}

bool AForm::getIsSigned() const
{
    return _isSigned;
}

std::ostream& operator<<(std::ostream& cout, const AForm& obj)
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

