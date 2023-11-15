#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string name, short grade) : _name(name), _grade(grade) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat& src) { *this = src; }

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
	_grade = rhs._grade;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs) {
	os << rhs.getName() << " bureaucrat grade " << rhs.getGrade() << std::endl;
	return os;
}

void Bureaucrat::upgradeGrade() {
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::demoteGrade() {
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm(const AForm& form) const {
	if (form.getIsSigned() == true)
		std::cout << _name << " signed " << form.getName() << std::endl;
	else if ((form.getIsSigned() == false) && (form.getGrade() < 1)) {
		std::cout	<< _name << " couldn't sign " << form.getName() << " because "
					<< form.getGrade() << "is lower than 1" << std::endl;
	}
	else if ((form.getIsSigned() == false) && (form.getGrade() > 150)) {
		std::cout	<< _name << " couldn't sign " << form.getName() << " because "
					<< form.getGrade() << "is greater than 150" << std::endl;
	}
} 

void Bureaucrat::executeForm(const AForm& form) {
	signForm(form);
	form.execute(*this);

	if ((getGrade() <= form.getGrade()) && form.getIsSigned() == true)
		std::cout << _name << " executed " << form.getName() << std::endl;
}

const std::string	Bureaucrat::getName() const { return _name; }
short				Bureaucrat::getGrade() const { return _grade; }

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high exception";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low exception";
}

const char* Bureaucrat::UnsignedFormularyException::what() const throw() {
	return "Unsigned formulary exception";
}