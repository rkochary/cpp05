#include "Bureaucrat.hpp"


int main()
{
   try
   {
    Bureaucrat example("John",2);
    example.increment();
    std::cout << example << std::endl;
    example.increment();
    std::cout << example << std::endl;
    example.increment();
    std::cout << example << std::endl;
    example.increment();
    std::cout << example << std::endl;
   }
   catch(const std::exception& e)
   {
    std::cerr << e.what() << '\n';
   }
    
}