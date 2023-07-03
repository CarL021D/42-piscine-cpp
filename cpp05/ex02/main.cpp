
#include <iostream>
#include <exception>
#include "includes/AForm.hpp"
#include "includes/Bureaucrat.hpp"
#include "includes/PresidentialPardonForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"

int main() {
		
	PresidentialPardonForm president("President");
	RobotomyRequestForm roboto("machine one");
	ShrubberyCreationForm shrubbery("mixer");

	try {

		Bureaucrat bureaucrat00("Bureaucrat00", 2);

		// // Test 1
		// president.beSigned(bureaucrat00);
		// president.execute(bureaucrat00);

		// // Test 2
		// roboto.beSigned(bureaucrat00);
		// roboto.execute(bureaucrat00);

		// // Test 3
		// shrubbery.beSigned(bureaucrat00);
		// shrubbery.execute(bureaucrat00);

		// // Test 4
		// president.execute(bureaucrat00);

		// // Test 5
		// president.execute(bureaucrat00);

		// // Test 6
		// president.execute(bureaucrat00);

		// // Test 7
		// president.beSigned(bureaucrat00);
		// bureaucrat00.executeForm(president);

		// // Test 8
		// bureaucrat00.executeForm(president);

	// } catch (std::exception const & e) {
	} catch (AForm::UnsignedFormularyException const & e) {
		std::cout << "Exception caught: [ " << e.what() << " ]" << std::endl;
	} catch (AForm::GradeTooHighException const & e) {
		std::cout << "Exception caught: [ " << e.what() << " ]" << std::endl;
	} catch (AForm::GradeTooLowException const & e) {
		std::cout << "Exception caught: [ " << e.what() << " ]" << std::endl;
	}
}