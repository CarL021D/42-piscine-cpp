#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int16_t grade) : _name(name) {
	if ( grade < 1)
		throw GradeTooHighexception;
	else if (grade > 150)
		throw GradeTooLowException;
	else
		this->_grade = grade;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat& cpy) { *this = cpy; }

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
	this->_name = rhs.getName();
	this->_grade = rhs.getGrade();
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs) {
	os << rhs.getName() << " bureaucrat grade " << rhs.getGrade() << std::endl;
	return os;
}



Bureaucrat& Bureaucrat::operator<<(std::ostream& os, const Bureaucrat& rhs) {
	std::os << rhs.getName() << "bureaucrat grade" << rhs.getGrade() << std::endl;
	return os;
}

void Bureaucrat::upgradeGrade() {
	if (this->_grade == 1)
		throw GradeTooHighexception;
	this->_grade--;
}

void Bureaucrat::demoteGrade() {
    if (this->_grade == 150)
        throw GradeTooLowException;
    this->_grade++;
}

std::string const Bureaucrat::getName() const { return this->_name; }

int16_t Bureaucrat::getGrade() const { return this->_grade; }
