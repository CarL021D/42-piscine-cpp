#include "includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string name, int16_t grade) : _name(name), _grade(grade) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat& cpy) { *this = cpy; }

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
	_grade = rhs._grade;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs) {
	os << rhs.getName() << " bureaucrat grade " << rhs.getGrade();
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

const std::string	Bureaucrat::getName() const { return _name; }
int16_t				Bureaucrat::getGrade() const { return _grade; }

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high exception";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low exception";
}