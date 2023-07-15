#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm",72,45)
{
    std::cout << "Robotomy Constructor" <<std::endl;
    _target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj)
{
    *this = obj;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
    if (this != &obj)
    {
        _target = obj._target;
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Destructor called for RobotomyRequestForm" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if(!getIsSigned())
    {
		throw AForm::SignedSuccessException();
    }

    if (executor.getGrade() > getReqExequteIt())
    {
        throw AForm::GradeTooLowException();
    }
    std::cout << " some drilling noises " << std::endl;
    std::srand(std::time(0));
    if(rand()%2 == 0)
    {
        std::cout << _target << " has been robotomized successfully " << std::endl;
    }
    else
    {
         std::cout << _target << " failed " << std::endl;
    }
}