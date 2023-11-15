
#include "AForm.hpp"

AForm::AForm() : _name(""), _signGrade(0), _execGrade(0), _isSigned(false) {}

AForm::AForm(const std::string& name, const short signGrade, const short execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade), _isSigned(false) {
	if (signGrade < 1)
		throw GradeTooHighException();
	else if (signGrade > 150)
		throw GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(const AForm& src) : _name(src._name), _signGrade(src._signGrade), _execGrade(src._execGrade) { *this = src; }

AForm& AForm::operator=(const AForm& rhs) {
	_isSigned = rhs._isSigned;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const AForm& rhs) {
	os << rhs.getName() << " Aform grade " << rhs.getGrade() << std::endl;
	return os;
}

void AForm::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= _signGrade) {
		_isSigned = true;
		std::cout << _name << " signed" << std::endl;
	}
	else {
		std::cout << bureaucrat.getName() << " can't sign " << _name << std::endl;
		throw GradeTooLowException();
	}
}

const std::string   AForm::getName() const { return _name; }
short				AForm::getGrade() const { return _signGrade; }
short				AForm::getExecGrade() const { return _execGrade; }
bool				AForm::getIsSigned() const { return _isSigned; }

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade too low!";
}

const char* AForm::UnsignedFormularyException::what() const throw() {
	return "Formulary not signed!";
}
