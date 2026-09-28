#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

class TestForm : public AForm
{
public:
	TestForm() : AForm("Test form", 50, 25) {}

	void executeAction() const
	{
		std::cout << "Test form action was performed." << std::endl;
	}
};

int main()
{
	TestForm form;
	Bureaucrat weak("Weak", 100);
	Bureaucrat signer("Signer", 50);
	Bureaucrat executor("Executor", 25);

	std::cout << "New form: " << form << std::endl;

	std::cout << "\n1. Try to execute before signing:" << std::endl;
	weak.executeForm(form);

	std::cout << "\n2. Try to sign with grade 100:" << std::endl;
	weak.signForm(form);

	std::cout << "\n3. Sign with grade 50:" << std::endl;
	signer.signForm(form);
	std::cout << "After signing: " << form << std::endl;

	std::cout << "\n4. Try to execute with grade 100:" << std::endl;
	weak.executeForm(form);

	std::cout << "\n5. Execute with grade 25:" << std::endl;
	executor.executeForm(form);

	return 0;
}
