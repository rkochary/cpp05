#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string);
        ShrubberyCreationForm(const ShrubberyCreationForm &obj);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm &obj);
        ~ShrubberyCreationForm();
        void execute(Bureaucrat const & executor) const;
    private:
        std::string _target;
};

#endif