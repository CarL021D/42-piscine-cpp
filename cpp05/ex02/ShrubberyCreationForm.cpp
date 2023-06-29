
#include "includes/ShrubberyCreationForm.hpp"
#include <fstream>
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm() : _name(""), _signGrade(0), _execGrade(0), _isSigned(false), _target("") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : _name(name), _signGrade(25), _execGrade(5), _isSigned(false) _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& cpy) : _name(cpy._name), _signGrade(cpy._signGrade), _execGrade(cpy._execGrade), _isSigned(cpy._isSigned) {}


ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) {
	this->_isSigned = rhs._isSigned;
	return *this;
}

void ShrubberyCreationForm::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= this->_signGrade) {
		this->_isSigned = true;
		std::cout << std::endl << this->_name << " signed" << std::endl;
	}
	else {
		std::cout << bureaucrat.getName() << " can't sign " << this->_name << std::endl;
		throw GradeTooLowException();
	}
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if (exception.getGrade() > this->_execGrade)
		throw GradeTooLowException();
	else if (this->_isSigned == false)
		throw FormularynotSignedException();

    std::cout << this->_target << " has been forgiven by Zaphod Beeblebrox" << std::endl;
}

const std::string   ShrubberyCreationForm::getName() const { return this->_name; }
int16_t				ShrubberyCreationForm::getGrade() const { return this->_signGrade; }
int16_t				ShrubberyCreationForm::getExecGrade() const { return this->_execGrade; }
bool				ShrubberyCreationForm::getIsSigned() const { return this->_isSigned; }

const char* ShrubberyCreationForm::GradeTooHighException::what() const throw() {
	return "Grade too high!";
}

const char* ShrubberyCreationForm::GradeTooLowException::what() const throw() {
	return "Grade too low!";
}

const char* ShrubberyCreationForm::FormularynotSignedException::what() const throw() {
	return "Formulary not signed!";
}
