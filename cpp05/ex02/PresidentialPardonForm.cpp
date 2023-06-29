
#include "includes/PresidentialPardonForm.hpp"
#include <fstream>
#include <string>

PresidentialPardonForm::PresidentialPardonForm() : _name(""), _signGrade(0), _execGrade(0), _isSigned(false), _target("") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("the president", 145, 137), _isSigned(false) _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& cpy) : _name(cpy._name), _signGrade(cpy._signGrade), _execGrade(cpy._execGrade), _isSigned(cpy._isSigned) {}


PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs) {
	this->_isSigned = rhs._isSigned;
	return *this;
}

void PresidentialPardonForm::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= this->_signGrade) {
		this->_isSigned = true;
		std::cout << std::endl << this->_name << " signed" << std::endl;
	}
	else {
		std::cout << bureaucrat.getName() << " can't sign " << this->_name << std::endl;
		throw GradeTooLowException();
	}
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	if (exception.getGrade() > this->_execGrade)
		throw GradeTooLowException();
	else if (this->_isSigned == false)
		throw FormularynotSignedException();

	std::ofstream file((this->_target + "_shrubbery").c_str());
	if (file.is_open()) {
		printTree(file);
	   file.close();
	}
	else
		std::cout << "The file could not be created" << std::endl;
}

const std::string   PresidentialPardonForm::getName() const { return this->_name; }
int16_t				PresidentialPardonForm::getGrade() const { return this->_signGrade; }
int16_t				PresidentialPardonForm::getExecGrade() const { return this->_execGrade; }
bool				PresidentialPardonForm::getIsSigned() const { return this->_isSigned; }

const char* PresidentialPardonForm::GradeTooHighException::what() const throw() {
	return "Grade too high!";
}

const char* PresidentialPardonForm::GradeTooLowException::what() const throw() {
	return "Grade too low!";
}

const char* PresidentialPardonForm::FormularynotSignedException::what() const throw() {
	return "Formulary not signed!";
}


void PresidentialPardonForm::printTree(std::ofstream& os) const {
	os <<	"             * *" << std::endl
			"           *    *  *" << std::endl
			"	  *  *    *     *  *" << std::endl
			"	 *     *    *  *    *" << std::endl
			" * *   *    *    *    *   *" << std::endl
			" *     *  *    * * .#  *   *" << std::endl
			" *   *     * #.  .# *   *" << std::endl
			"  *     \"#.  #: #\" * *    *" << std::endl
			" *   * * \"#. ##\"       *" << std::endl
			"   *       \"###" << std::endl
			"			 \"##" << std::endl
			"			  ##." << std::endl
			"			  .##:" << std::endl
			"			  :###" << std::endl
			"			  ;###" << std::endl
			"			,####." << std::endl
			"/\\/\\/\\/\\/\\/.######.\\/\\/\\/\\/\\" << std::endl
}
