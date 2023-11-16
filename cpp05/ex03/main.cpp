
#include <iostream>
#include <exception>
#include "includes/AForm.hpp"
#include "includes/Bureaucrat.hpp"
#include "includes/PresidentialPardonForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/Intern.hpp"

int main() {

	AForm* form;
	Intern	intern;

	try {
		// Test1
		Bureaucrat bureaucrat00("Bureaucrat00", 2);
		form = intern.makeForm("president", "Mister1");
		form->beSigned(bureaucrat00);
		form->execute(bureaucrat00);

		// // Test 2
		// Bureaucrat bureaucrat00("Bureaucrat00", 2);
		// form = intern.makeForm("roboto", "Mister1");
		// form->beSigned(bureaucrat00);
		// form->execute(bureaucrat00);

		// // Test 3
		// Bureaucrat bureaucrat00("Bureaucrat00", 2);
		// form = intern.makeForm("shruberry", "Mister1");
		// form->beSigned(bureaucrat00);
		// form->execute(bureaucrat00);

		// // Test 4
		// Bureaucrat bureaucrat00("Bureaucrat00", 2);
		// form = intern.makeForm("moon", "Mister1");
		// if (form != NULL)
		// {
		// 	form->beSigned(bureaucrat00);
		// 	form->execute(bureaucrat00);
		// }

	} catch (AForm::UnsignedFormularyException const & e) {
		std::cout << "Exception caught: [ " << e.what() << " ]" << std::endl;
	} catch (AForm::GradeTooHighException const & e) {
		std::cout << "Exception caught: [ " << e.what() << " ]" << std::endl;
	} catch (AForm::GradeTooLowException const & e) {
		std::cout << "Exception caught: [ " << e.what() << " ]" << std::endl;
	}

	// PresidentialPardonForm president("President");
	// RobotomyRequestForm roboto("machine one");
	// ShrubberyCreationForm shrubbery("mixer");

	// try {

	// 	Bureaucrat bureaucrat00("Bureaucrat00", 2);

	// 	// Test 1
	// 	president.beSigned(bureaucrat00);
	// 	president.execute(bureaucrat00);

	// 	// // Test 2
	// 	// roboto.beSigned(bureaucrat00);
	// 	// roboto.execute(bureaucrat00);

	// 	// // Test 3
	// 	// shrubbery.beSigned(bureaucrat00);
	// 	// shrubbery.execute(bureaucrat00);

	// 	// // Test 4
	// 	// president.execute(bureaucrat00);

	// 	// // Test 5
	// 	// president.execute(bureaucrat00);

	// 	// // Test 6
	// 	// president.execute(bureaucrat00);


	// // } catch (std::exception const & e) {
	// } catch (AForm::UnsignedFormularyException const & e) {
	// 	std::cout << "Exception caught: [ " << e.what() << " ]" << std::endl;
	// } catch (AForm::GradeTooHighException const & e) {
	// 	std::cout << "Exception caught: [ " << e.what() << " ]" << std::endl;
	// } catch (AForm::GradeTooLowException const & e) {
	// 	std::cout << "Exception caught: [ " << e.what() << " ]" << std::endl;
	// }
}