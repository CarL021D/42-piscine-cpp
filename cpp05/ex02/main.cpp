
#include <iostream>
#include <cstdint>
#include <exception>
#include "includes/AForm.hpp"
#include "includes/Bureaucrat.hpp"
#include "includes/PresidentialPardonForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"

int main() {
		
	Bureaucrat *bureaucrat00;
	
	AForm president = PresidentialPardonForm("President");
	// AForm roboto = RobotomyRequestForm("machine one");
	// AForm shrubbery =  ShrubberyCreationForm("mixer");

	try {

		// Test 1: every Methods are executed
		bureaucrat00("Bureaucrat00", 2);

		president.execute(bureaucrat00);

		// // Test 2: unsigned formulary excecption caught
		// bureaucrat00("Bureaucrat00", toSet);

		// // Test 3: grade to low exception caught 
		// bureaucrat00("Bureaucrat00", toSet);

		// // Test 4: grade exception caught
		// bureaucrat00("Bureaucrat00", toSet);


	} catch (Bureaucrat::GradeTooHighException& e1) {
		std::cout << "Grade to high exception caught" << std::endl << e1.what() << std::endl;
		// freeFormAllocations(president, roboto, shrubbery);
	} catch (Bureaucrat::GradeTooLowException& e1) {
		std::cout << "Grade to low exception caught" << std::endl << e1.what() << std::endl;
		// freeFormAllocations(president, roboto, shrubbery);
	} catch (AForm::GradeTooHighException& e2) {
		std::cout << "Grade to high exception caught" << std::endl << e2.what() << std::endl;
		// freeFormAllocations(president, roboto, shrubbery);
	} catch (AForm::GradeTooLowException& e2) {
		std::cout << "Grade to low exception" << std::endl << e2.what() << std::endl;
		// freeFormAllocations(president, roboto, shrubbery);
	} catch (AForm::UnsignedFormulary& e2) {
		std::cout << "Unsigned formulary exception caught" << std::endl << e.what() << std::endl;
		// freeFormAllocations(president, roboto, shrubbery);
	}
}