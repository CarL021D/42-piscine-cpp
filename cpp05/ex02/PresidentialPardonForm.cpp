
#include "includes/PresidentialPardonForm.hpp"
#include <fstream>
#include <string>

PresidentialPardonForm::PresidentialPardonForm() : _name(""), _grade(0), _execGrade(0), _isSigned(false), _target("") {}

// PresidentialPardonForm::PresidentialPardonForm(const std::string& name, const int16_t grade) : _name(name), _grade(grade), _execGrade(0), _isSigned(false) {
// 	if (grade < 1)
// 		throw GradeTooHighException();
// 	else if (grade > 150)
// 		throw GradeTooLowException();
// }

PresidentialPardonForm::PresidentialPardonForm(std::string target) : _name(name), _signGrade(145), _execGrade(137), _isSigned(false) _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& cpy) : _name(cpy._name), _grade(cpy._grade), _execGrade(cpy._execGrade), _isSigned(cpy._isSigned) {}


PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs) {
	this->_isSigned = rhs._isSigned;
	return *this;
}

// std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& rhs) {
// 	os << rhs.getName() << " PresidentialPardonForm grade " << rhs.getGrade() << std::endl;
// 	return os;
// }

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

	std::ofstream file((this->_target + "_shrubbery").c_str());
	if (file.isOpen()) {


	   file.close() 
	}
	else
		std::cout << "The file  could not be created" << swtd::cout;
}

void PresidentialPardonForm::printTree(std::ofstream os) {
	std::os <<	"             * *" << std::endl
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

const std::string   PresidentialPardonForm::getName() const { return this->_name; }
int16_t				PresidentialPardonForm::getGrade() const { return this->_grade; }
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
