
#include "includes/ShrubberyCreationForm.hpp"
#include <fstream>
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("shrubCreation", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& cpy) { *this = cpy; }


ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) {
	this->_isSigned = rhs._isSigned;
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if (executor.getGrade() > this->_execGrade)
		throw GradeTooLowException();
	else if (this->_isSigned == false)
		throw UnsignedFormularyException();

    std::cout << this->_target << " has been forgiven by Zaphod Beeblebrox" << std::endl;
}

