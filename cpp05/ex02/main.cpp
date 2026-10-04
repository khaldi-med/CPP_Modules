#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
    std::srand(static_cast<unsigned int>(std::time(0)));

    ShrubberyCreationForm shrubbery("tree");
    RobotomyRequestForm robotomy("Bender");
    PresidentialPardonForm pardon("Bender");
    Bureaucrat signer("Signer", 145);
    Bureaucrat executor("Executor", 137);
    Bureaucrat robotomySigner("Robotomy Signer", 72);
    Bureaucrat robotomyExecutor("Robotomy Executor", 45);
    Bureaucrat pardonSigner("Pardon Signer", 25);
    Bureaucrat pardonExecutor("Pardon Executor", 5);

    std::cout << "New shrubbery form: " << shrubbery << std::endl;
    std::cout << "New robotomy form: " << robotomy << std::endl;
    std::cout << "New presidential pardon form: " << pardon << std::endl;

    std::cout << "\n1. Try to execute before signing:" << std::endl;
    try {
        Bureaucrat weak("Weak", 100);
        weak.executeForm(shrubbery);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n2. Sign the shrubbery form with grade 145:" << std::endl;
    signer.signForm(shrubbery);
    std::cout << "After signing: " << shrubbery << std::endl;

    std::cout << "\n3. Execute the shrubbery form with grade 137:" << std::endl;
    executor.executeForm(shrubbery);

    std::cout << "\n4. Sign and execute the robotomy form with valid grades:" << std::endl;
    robotomySigner.signForm(robotomy);
    robotomyExecutor.executeForm(robotomy);

    std::cout << "\n5. Sign and execute the presidential pardon form with valid grades:" << std::endl;
    pardonSigner.signForm(pardon);
    pardonExecutor.executeForm(pardon);

    return 0;
}
