
#include "Form.hpp"

Form::Form() : _name(""), _grade(0), _execGrade(0), _isSigned(false) {}

Form::Form(const std::string& name, const int16_t grade) : _name(name), _grade(grade), _execGrade(0), _isSigned(false) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

Form::~Form() {}

Form::Form(const Form& cpy) : _name(cpy._name), _grade(cpy._grade), _execGrade(cpy._execGrade), _isSigned(cpy._isSigned) {}

Form& Form::operator=(const Form& rhs) {
	this->_isSigned = rhs._isSigned;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Form& rhs) {
	os << rhs.getName() << " form grade " << rhs.getGrade() << std::endl;
	return os;
}

void Form::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= this->_grade) {
		this->_isSigned = true;
		std::cout << std::endl << this->_name << " signed" << std::endl;
	}
	else {
		std::cout << bureaucrat.getName() << " can't sign " << this->_name << std::endl;
		throw GradeTooLowException();
	}
}

const std::string   Form::getName() const { return this->_name; }
int16_t				Form::getGrade() const { return this->_grade; }
int16_t				Form::getExecGrade() const { return this->_execGrade; }
bool				Form::getIsSigned() const { return this->_isSigned; }

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade too low!";
}