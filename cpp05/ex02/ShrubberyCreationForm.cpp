#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <stdexcept>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137), target("default_target") {}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("Shrubbery Creation Form", 145, 137), target(target) {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.target) {}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
    }
    return *this;
}

const std::string& ShrubberyCreationForm::getTarget() const
{
    return target;
}

void ShrubberyCreationForm::executeAction() const
{
    const std::string filename = target + "_shrubbery";
    std::ofstream file(filename.c_str());
    if (file.is_open())
    {
        file << "       _-_\n";
        file << "    /~~   ~~\\\n";
        file << " /~~         ~~\\\n";
        file << "{               }\n";
        file << " \\  _-     -_  /\n";
        file << "   ~  \\\\ //  ~\n";
        file << "_- -   | | _- _\n";
        file << "  _ -  | |   -_\n";
        file << "      // \\\\\n";
        file.close();
    }
    else
    {
        throw std::runtime_error("Failed to create the shrubbery file");
    }
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}