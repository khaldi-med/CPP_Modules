#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Robotomy Request Form", 72, 45), target("default_target") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("Robotomy Request Form", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), target(other.target) {}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
  if (this != &other)
    AForm::operator=(other);
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

const std::string &RobotomyRequestForm::getTarget() const { return target; }

void RobotomyRequestForm::executeAction() const {
  std::cout << "* BZZZZZT! Drilling noises... *" << std::endl;
  if (std::rand() % 2 == 0)
    std::cout << target << " has been robotomized successfully!" << std::endl;
  else
    std::cout << "Failed to robotomize " << target << "." << std::endl;
}
