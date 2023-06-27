
#include "Form.hpp"

Form::Form() {
	_name = "";
	_isSigned = false;
	_grade = 0;
	_execGrade = 0;
}

Form::Form(const std::string& name, int16_t grade)
{
	_name = name;
	_isSigned = false;
	_execGrade = 0;

	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		_grade = grade;
}

Form::~Form() {}

Form::Form(const Form& cpy) { *this = cpy; }

Form& Form::operator=(const Form& rhs) {
	this->_name = rhs._name;
	this->_isSigned = rhs._isSigned;
	this->_grade = rhs._grade;
	this->execGrade = rhs._execGrade;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Form& rhs) {
	os << rhs.getName() << " form grade " << rhs.getGrade() << std::endl;
	return os;
}

void Form::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() < 1)
	{
		std::cout << this->_name << " couldn't sign " << bureaucrat.getName() << " because ";
		throw GradeTooHighException();
	}
	else if (bureaucrat.getGrade() > 150) {
		std::cout << this->_name << " couldn't sign " << bureaucrat.getName() << " because ";
		throw GradeTooLowException();
	}
	else {
		this->_isSigned = true;
		std::cout << bureaucrat.getName() << " signed " << this->_name << std::endl;
	}
}

const std::string   Form::getName() const { return this->_name; }

int16_t				Form::getGrade() const { return this->_grade; }

int16_t				Form::getExecGrade() const { return this->_execGrade; }

bool				Form::getIsSinged() const { return this->_isSigned; }

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade to high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade to low!";
}