
#include "includes/ShrubberyCreationForm.hpp"
#include <fstream>
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("shrubCreation", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) { *this = src; }


ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) {
	this->_isSigned = rhs._isSigned;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& rhs) {
	os << rhs.getName() << " RobotomyRequestForm grade " << rhs.getGrade() << std::endl;
	return os;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
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

void ShrubberyCreationForm::printTree(std::ofstream& os) const {
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