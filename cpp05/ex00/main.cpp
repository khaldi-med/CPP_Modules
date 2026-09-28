#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    try
    {
        Bureaucrat alice("Alice", 2);
        std::cout << alice << std::endl;
        alice.incrementGrade();
        std::cout << alice << std::endl;
        alice.incrementGrade();
    }
    catch (const std::exception& exception)
    {
        std::cout << exception.what() << std::endl;
    }

    try
    {
        Bureaucrat bob("Bob", 151);
    }
    catch (const std::exception& exception)
    {
        std::cout << exception.what() << std::endl;
    }
    return 0;
}
