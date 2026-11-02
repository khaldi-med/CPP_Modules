#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
  std::srand(static_cast<unsigned int>(std::time(0)));

  Intern someRandomIntern;

  Bureaucrat lowRank("LowRank Clerk", 150);
  Bureaucrat midRank("MidRank Manager", 45);
  Bureaucrat topRank("President", 1);

  std::cout << "=== 1. INTERN FORM CREATION ===" << std::endl;
  AForm *shrubbery = someRandomIntern.makeForm("shrubbery creation", "home");
  AForm *robotomy = someRandomIntern.makeForm("robotomy request", "Bender");
  AForm *pardon =
      someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
  AForm *unknown = someRandomIntern.makeForm("coffee request", "office");

  std::cout << "\n=== 2. TEST UNSIGNED EXECUTION & LOW GRADE ERRORS ==="
            << std::endl;
  if (shrubbery != NULL) {
    topRank.executeForm(*shrubbery); // Should fail: not signed yet
    lowRank.signForm(*shrubbery);    // Should fail: grade 150 > 145
  }

  std::cout
      << "\n=== 3. SIGN & EXECUTE SHRUBBERY FORM (Sign: 145, Exec: 137) ==="
      << std::endl;
  if (shrubbery != NULL) {
    midRank.signForm(*shrubbery);
    lowRank.executeForm(*shrubbery); // Should fail: grade 150 > 137
    midRank.executeForm(*shrubbery); // Should succeed and create home_shrubbery
    delete shrubbery;
  }

  std::cout << "\n=== 4. SIGN & EXECUTE ROBOTOMY FORM (Sign: 72, Exec: 45) ==="
            << std::endl;
  if (robotomy != NULL) {
    midRank.signForm(*robotomy);
    midRank.executeForm(*robotomy);
    delete robotomy;
  }

  std::cout << "\n=== 5. SIGN & EXECUTE PRESIDENTIAL PARDON FORM (Sign: 25, "
               "Exec: 5) ==="
            << std::endl;
  if (pardon != NULL) {
    midRank.signForm(*pardon); // Should fail: grade 45 > 25
    topRank.signForm(*pardon);
    topRank.executeForm(*pardon);
    delete pardon;
  }

  if (unknown != NULL)
    delete unknown;

  return 0;
}
