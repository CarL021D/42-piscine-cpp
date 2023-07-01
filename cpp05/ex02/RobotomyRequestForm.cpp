
#include "includes/RobotomyRequestForm.hpp"
#include <fstream>
#include <string>

RobotomyRequestForm::RobotomyRequestForm() : _name(""), _signGrade(0), _execGrade(0), _isSigned(false), _target("") {}

// RobotomyRequestForm::RobotomyRequestForm(const std::string& name, const int16_t grade) : _name(name), _signGrade(grade), _execGrade(0), _isSigned(false) {
// 	if (grade < 1)
// 		throw GradeTooHighException();
// 	else if (grade > 150)
// 		throw GradeTooLowException();
// }

RobotomyRequestForm::RobotomyRequestForm(std::string target) : _name(name), _signGrade(72), _execGrade(45), _isSigned(false) _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& cpy) : _name(cpy._name), _signGrade(cpy._signGrade), _execGrade(cpy._execGrade), _isSigned(cpy._isSigned) {}


RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs) {
	this->_isSigned = rhs._isSigned;
	return *this;
}

// std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& rhs) {
// 	os << rhs.getName() << " RobotomyRequestForm grade " << rhs.getGrade() << std::endl;
// 	return os;
// }

void RobotomyRequestForm::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= this->_signGrade) {
		this->_isSigned = true;
		std::cout << std::endl << this->_name << " signed" << std::endl;
	}
	else {
		std::cout << bureaucrat.getName() << " can't sign " << this->_name << std::endl;
		throw GradeTooLowException();
	}
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	if (exception.getGrade() > this->_execGrade)
		throw GradeTooLowException();
	else if (this->_isSigned == false)
		throw UnsignedFormulary();

	srand(time(NULL));
	int32_t randomNumber = rand() % 2;
	if (randomNumber)
		std::cout << this->_target << "has been robotized with success!" << std::endl;
	else
		std::cout << "Robotized operation on " << this->_target << " failed!" << std::endl;
}

const std::string   RobotomyRequestForm::getName() const { return this->_name; }
int16_t				RobotomyRequestForm::getGrade() const { return this->_signGrade; }
int16_t				RobotomyRequestForm::getExecGrade() const { return this->_execGrade; }
bool				RobotomyRequestForm::getIsSigned() const { return this->_isSigned; }

const char* RobotomyRequestForm::GradeTooHighException::what() const throw() {
	return "Grade too high!";
}

const char* RobotomyRequestForm::GradeTooLowException::what() const throw() {
	return "Grade too low!";
}

const char* RobotomyRequestForm::UnsignedFormulary::what() const throw() {
	return "Formulary not signed!";
}
