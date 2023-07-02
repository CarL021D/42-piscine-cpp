
#include "includes/RobotomyRequestForm.hpp"
#include <fstream>
#include <cstdlib>
#include <string>

RobotomyRequestForm::RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Trob", 72, 45), _target(target) {
	// this->_isSigned = false;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& cpy) { *this = cpy; }


RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs) {
	this->_isSigned = rhs._isSigned;
	return *this;
}

// std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& rhs) {
// 	os << rhs.getName() << " RobotomyRequestForm grade " << rhs.getGrade() << std::endl;
// 	return os;
// }

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	if (executor.getGrade() > this->_execGrade)
		throw GradeTooLowException();
	else if (this->_isSigned == false)
		throw UnsignedFormularyException();

	srand(time(NULL));
	int randomNumber = rand() % 2;
	if (randomNumber % 2)
		std::cout << this->_target << " has been robotized with success!" << std::endl;
	else
		std::cout << "Robotized operation on " << this->_target << " failed!" << std::endl;
}
