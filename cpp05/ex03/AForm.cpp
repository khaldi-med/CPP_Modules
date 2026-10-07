#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>


const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

AForm::AForm(): name(""), isSigned(false), gradeToSign(150), gradeToExecute(150) {}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}
AForm::AForm(const AForm& other): name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

AForm& AForm::operator=(const AForm& other){
    if (this != &other) {
        this->isSigned = other.isSigned;
    }
    return *this;
}

const std::string& AForm::getName() const
{
    return name;
}
bool AForm::getIsSigned() const {
    return isSigned;
}
int AForm::getGradeToSign() const {
    return gradeToSign;
}
int AForm::getGradeToExecute() const {
    return gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}
void AForm::execute(const Bureaucrat& bureaucrat) const
{
    if (!isSigned)
        throw std::runtime_error("Form is not signed");    
    if (bureaucrat.getGrade() > gradeToExecute)
        throw GradeTooLowException();
    executeAction();
}

AForm::~AForm() {}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    os << "Form Name: " << form.getName() << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
       << ", Grade to Sign: " << form.getGradeToSign() << ", Grade to Execute: " << form.getGradeToExecute();
    return os;
}