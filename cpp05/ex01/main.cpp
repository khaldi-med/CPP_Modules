#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    std::cout << "--- Form construction and getters ---" << std::endl;
    try
    {
        Form defaultForm;
        std::cout << "Default form: " << defaultForm << std::endl;
        Form form("Form A", 30, 20);
        std::cout << "Custom form: " << form << std::endl;
    }
    catch (const std::exception& exception)
    {
        std::cout << "Unexpected exception: " << exception.what() << std::endl;
    }

    std::cout << "\n--- Invalid form grades ---" << std::endl;
    try
    {
        Form form("Too high", 0, 20);
        std::cout << "No exception: invalid grade was accepted" << std::endl;
    }
    catch (const Form::GradeTooHighException&)
    {
        std::cout << "Exception caught: grade 0 is too high" << std::endl;
    }

    try
    {
        Form form("Too low", 30, 151);
        std::cout << "No exception: invalid grade was accepted" << std::endl;
    }
    catch (const Form::GradeTooLowException&)
    {
        std::cout << "Exception caught: grade 151 is too low" << std::endl;
    }

    std::cout << "\n--- Form copy and assignment ---" << std::endl;
    try
    {
        Bureaucrat manager("Manager", 10);
        Form original("Original", 50, 25);
        original.beSigned(manager);

        Form copied(original);
        std::cout << "Copied form: " << copied << std::endl;

        Form assigned("Assigned", 100, 80);
        assigned = original;
        std::cout << "Assigned form: " << assigned << std::endl;
    }
    catch (const std::exception& exception)
    {
        std::cout << "Unexpected exception: " << exception.what() << std::endl;
    }

    std::cout << "\n--- Bureaucrat grade boundaries ---" << std::endl;
    try
    {
        Bureaucrat highest("Highest", 1);
        highest.incrementGrade();
        std::cout << "No exception: grade 1 became " << highest.getGrade()
                  << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException&)
    {
        std::cout << "Exception caught: grade 1 cannot be increased" << std::endl;
    }

    try
    {
        Bureaucrat lowest("Lowest", 150);
        lowest.decrementGrade();
        std::cout << "No exception: grade 150 became " << lowest.getGrade()
                  << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException&)
    {
        std::cout << "Exception caught: grade 150 cannot be decreased" << std::endl;
    }

    std::cout << "\n--- Signing rules ---" << std::endl;
    Form form("Important Form", 50, 25);
    Bureaucrat weak("Weak", 80);
    Bureaucrat strong("Strong", 50);

    try
    {
        form.beSigned(weak);
          std::cout << "No exception: grade 80 signed the form" << std::endl;
    }
    catch (const Form::GradeTooLowException&)
    {
          std::cout << "Exception caught: grade 80 cannot sign a grade 50 form"
                << std::endl;
    }

    try
    {
        form.beSigned(strong);
          std::cout << "After grade 50 signs: " << form << std::endl;
    }
    catch (const std::exception& exception)
    {
          std::cout << "Unexpected exception: " << exception.what() << std::endl;
    }

    Form report("Report", 25, 10);
    Bureaucrat junior("Junior", 100);
    Bureaucrat director("Director", 1);
    junior.signForm(report);
    director.signForm(report);
    std::cout << "Final report: " << report << std::endl;

    return 0;
}