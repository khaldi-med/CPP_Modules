#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern &other) { (void)other; }

Intern &Intern::operator=(const Intern &other) {
  (void)other;
  return *this;
}

Intern::~Intern() {}

AForm *Intern::makeForm(const std::string &formName,
                        const std::string &target) const {
  static const std::string formNames[3] = {
      "shrubbery creation", "robotomy request", "presidential pardon"};

  int formType = -1;
  for (int i = 0; i < 3; ++i) {
    if (formName == formNames[i]) {
      formType = i;
      break;
    }
  }

  AForm *form = NULL;
  switch (formType) {
  case 0:
    form = new ShrubberyCreationForm(target);
    break;
  case 1:
    form = new RobotomyRequestForm(target);
    break;
  case 2:
    form = new PresidentialPardonForm(target);
    break;
  default:
    std::cout << "Intern cannot create \"" << formName
              << "\" because the form name is unknown." << std::endl;
    return NULL;
  }

  std::cout << "Intern creates " << formName << std::endl;
  return form;
}
