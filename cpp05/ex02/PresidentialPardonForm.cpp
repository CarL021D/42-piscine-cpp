
#include "includes/PresidentialPardonForm.hpp"
#include <fstream>
#include <string>

PresidentialPardonForm::PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {
	// this->_isSigned = false;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& cpy) { *this = cpy; }

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs) {
	this->_isSigned = rhs._isSigned;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& rhs) {
	os << rhs.getName() << " PresidentialPardonForm grade " << rhs.getGrade() << std::endl;
	return os;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	if (executor.getGrade() > this->_execGrade)
		throw GradeTooLowException();
	else if (this->_isSigned == false)
		throw UnsignedFormularyException();

	std::cout << std::endl << "HERE" << std::endl;

	std::ofstream file((this->_target + "_shrubbery").c_str());
	if (file.is_open()) {
		printTree(file);
	   file.close();
	}
	else
		std::cout << "The file could not be created" << std::endl;
}

void PresidentialPardonForm::printTree(std::ofstream& os) const {
	os	<< "             * *" << std::endl
		<< "           *    *  *" << std::endl
		<< "	  *  *    *     *  *" << std::endl
		<< "	 *     *    *  *    *" << std::endl
		<< " * *   *    *    *    *   *" << std::endl
		<< " *     *  *    * * .#  *   *" << std::endl
		<< " *   *     * #.  .# *   *" << std::endl
		<< "  *     \"#.  #: #\" * *    *" << std::endl
		<< " *   * * \"#. ##\"       *" << std::endl
		<< "   *       \"###" << std::endl
		<< "			 \"##" << std::endl
		<< "			  ##." << std::endl
		<< "			  .##:" << std::endl
		<< "			  :###" << std::endl
		<< "			  ;###" << std::endl
		<< "			,####." << std::endl
		<< "/\\/\\/\\/\\/\\/.######.\\/\\/\\/\\/\\" << std::endl;
}
