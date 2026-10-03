#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>


int main()
{
	ShrubberyCreationForm form("tree");
	Bureaucrat signer("Signer", 145);
	Bureaucrat executor("Executor", 137);

	std::cout << "New form: " << form << std::endl;

	std::cout << "\n1. Try to execute before signing:" << std::endl;
	try {
		Bureaucrat weak("Weak", 100);
		weak.executeForm(form);
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n2. Try to sign with grade 100:" << std::endl;
	try {
		Bureaucrat weak("Weak", 100);
		weak.signForm(form);
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n3. Sign with grade 145:" << std::endl;
	signer.signForm(form);
	std::cout << "After signing: " << form << std::endl;

	std::cout << "\n4. Try to execute with grade 100:" << std::endl;
	try {
		Bureaucrat weak("Weak", 100);
		weak.executeForm(form);
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n5. Execute with grade 137:" << std::endl;
	executor.executeForm(form);

	return 0;
}
