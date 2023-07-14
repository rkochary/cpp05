#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"
#include <fstream>
#include <cstdlib>
#include <ctime>

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string);
        PresidentialPardonForm(const PresidentialPardonForm &obj);
        PresidentialPardonForm& operator=(const PresidentialPardonForm &obj);
        ~PresidentialPardonForm();
        void execute(Bureaucrat const & executor) const;
    private:
        std::string _target;
};

#endif