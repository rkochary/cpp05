#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"


int main()
{
    Bureaucrat buro("John", 2);
    ShrubberyCreationForm shrubbery("Garden");
    shrubbery.beSigned(buro);
}