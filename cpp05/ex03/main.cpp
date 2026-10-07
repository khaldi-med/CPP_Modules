#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
    std::srand(static_cast<unsigned int>(std::time(0)));

    Intern intern;
    Bureaucrat shrubberySigner("Shrubbery Signer", 145);
    Bureaucrat shrubberyExecutor("Shrubbery Executor", 137);
    Bureaucrat robotomySigner("Robotomy Signer", 72);
    Bureaucrat robotomyExecutor("Robotomy Executor", 45);
    Bureaucrat pardonSigner("Pardon Signer", 25);
    Bureaucrat pardonExecutor("Pardon Executor", 5);

    AForm* shrubbery = intern.makeForm("shrubbery creation", "home");
    AForm* robotomy = intern.makeForm("robotomy request", "Bender");
    AForm* pardon = intern.makeForm("presidential pardon", "Arthur Dent");
    AForm* unknown = intern.makeForm("coffee request", "home");

    if (shrubbery != NULL)
    {
        shrubberySigner.signForm(*shrubbery);
        shrubberyExecutor.executeForm(*shrubbery);
        delete shrubbery;
    }
    if (robotomy != NULL)
    {
        robotomySigner.signForm(*robotomy);
        robotomyExecutor.executeForm(*robotomy);
        delete robotomy;
    }
    if (pardon != NULL)
    {
        pardonSigner.signForm(*pardon);
        pardonExecutor.executeForm(*pardon);
        delete pardon;
    }
    if (unknown == NULL)
        std::cout << "Unknown form was not created" << std::endl;

    return 0;
}
