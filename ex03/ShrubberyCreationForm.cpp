#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm",145,137)
{
    std::cout << "Shrubbery Constructor" <<std::endl;
    _target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj)
{
    *this = obj;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
    if (this != &obj)
    {
        _target = obj._target;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
  std::cout << "Destructor called for ShrubberyCreationForm" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if(!getIsSigned())
    {
		throw AForm::SignedSuccessException();
    }

    if (executor.getGrade() > getReqExequteIt())
    {
        throw AForm::GradeTooLowException();
    }

    std::string filename = _target + "_shrubbery";
    std::ofstream outFile(filename);

    if (outFile.is_open()) {
        outFile <<	"     v"  <<std::endl
        <<  "     >X<" <<std::endl
        <<   "     A" <<std::endl
        <<  "     d$b" <<std::endl
        <<   "  .d\\$$b." <<std::endl
        <<  " .d$i$$\\$$b." <<std::endl
        <<  "    d$$@" <<std::endl
        <<  "   d\\$$$i" <<std::endl
        << "  .d$$$\\$$$" <<std::endl
        <<" .d$$@$$$$\\$$ib" <<std::endl
        << "    d$$i$$" <<std::endl
        << "   d\\$$$$@$" <<std::endl
        <<"  .d$@$$\\$$$$$@b" <<std::endl
        <<".d$$$$i$$$\\$$$$$$b" <<std::endl
        << "       ##" <<std::endl
        <<  "      ##" <<std::endl
        <<  "      ### mh" <<std::endl;
        outFile.close();
    } else {
        throw std::runtime_error("Unable to create file: " + filename);
    }
}