
#include "AForm.hpp"

AForm::AForm() : _name(""), _signGrade(0), _execGrade(0), _isSigned(false) {}

AForm::AForm(const std::string& name, const short signGrade, const short execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade), _isSigned(false) {
	if (signGrade < 1)
		throw GradeTooHighException();
	else if (signGrade > 150)
		throw GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(const AForm& cpy) : _name(cpy._name), _signGrade(cpy._signGrade), _execGrade(cpy._execGrade) { *this = cpy; }

AForm& AForm::operator=(const AForm& rhs) {
	this->_isSigned = rhs._isSigned;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const AForm& rhs) {
	os << rhs.getName() << " Aform grade " << rhs.getGrade() << std::endl;
	return os;
}

void AForm::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= this->_signGrade) {
		this->_isSigned = true;
		std::cout << std::endl << this->_name << " signed" << std::endl;
	}
	else {
		std::cout << bureaucrat.getName() << " can't sign " << this->_name << std::endl;
		throw GradeTooLowException();
	}
}

const std::string   AForm::getName() const { return this->_name; }
short				AForm::getGrade() const { return this->_signGrade; }
short				AForm::getExecGrade() const { return this->_execGrade; }
bool				AForm::getIsSigned() const { return this->_isSigned; }

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade too low!";
}

const char* AForm::UnsignedFormularyException::what() const throw() {
	return "Formulary not signed!";
}
