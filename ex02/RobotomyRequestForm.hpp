#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"
#include <fstream>
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string);
        RobotomyRequestForm(const RobotomyRequestForm &obj);
        RobotomyRequestForm& operator=(const RobotomyRequestForm &obj);
        ~RobotomyRequestForm();
        void execute(Bureaucrat const & executor) const;
    private:
        std::string _target;
};

#endif