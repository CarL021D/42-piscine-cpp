
#include "AForm.hpp"

AForm::AForm() : _name(""), _grade(0), _execGrade(0), _isSigned(false) {}

AForm::AForm(const std::string& name, const int16_t grade) : _name(name), _grade(grade), _execGrade(0), _isSigned(false) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(const AForm& cpy) : _name(cpy._name), _grade(cpy._grade), _execGrade(cpy._execGrade), _isSigned(cpy._isSigned) {}

AForm& AForm::operator=(const AForm& rhs) {
	this->_isSigned = rhs._isSigned;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const AForm& rhs) {
	os << rhs.getName() << " Aform grade " << rhs.getGrade() << std::endl;
	return os;
}

void AForm::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= this->_grade) {
		this->_isSigned = true;
		std::cout << std::endl << this->_name << " signed" << std::endl;
	}
	else {
		std::cout << bureaucrat.getName() << " can't sign " << this->_name << std::endl;
		throw GradeTooLowException();
	}
}

const std::string   AForm::getName() const { return this->_name; }
int16_t				AForm::getGrade() const { return this->_grade; }
int16_t				AForm::getExecGrade() const { return this->_execGrade; }
bool				AForm::getIsSigned() const { return this->_isSigned; }

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade too low!";
}