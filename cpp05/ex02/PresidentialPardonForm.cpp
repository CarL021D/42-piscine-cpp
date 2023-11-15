
#include "includes/PresidentialPardonForm.hpp"
#include <fstream>
#include <string>

PresidentialPardonForm::PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(std::string name) : AForm(name, 25, 5) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : AForm(src._name, 25, 5) { *this = src; }

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs) {

	_isSigned = rhs._isSigned;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& rhs) {
	os << rhs.getName() << " PresidentialPardonForm grade " << rhs.getGrade() << std::endl;
	return os;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	if (executor.getGrade() > _execGrade)
		throw GradeTooLowException();
	else if (_isSigned == false)
		throw UnsignedFormularyException();

    std::cout << executor.getName() << " has been forgiven by Zaphod Beeblebrox" << std::endl;
}
