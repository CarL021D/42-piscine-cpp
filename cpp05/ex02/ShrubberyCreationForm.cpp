
#include "includes/ShrubberyCreationForm.hpp"
#include <fstream>
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : AForm(name, 145, 137) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm(src._name, 72, 45) { *this = src; }

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) {
	_isSigned = rhs._isSigned;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& rhs) {
	os << rhs.getName() << " RobotomyRequestForm grade " << rhs.getGrade() << std::endl;
	return os;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if (executor.getGrade() > _execGrade)
		throw GradeTooLowException();
	else if (_isSigned == false)
		throw UnsignedFormularyException();

	std::ofstream file((executor.getName() + "_shrubbery").c_str());
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