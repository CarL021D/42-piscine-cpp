
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

		// Test 1: every Methods are executed
		Bureaucrat bureaucrat00("Bureaucrat00", 2);

		president.execute(bureaucrat00);

		// // Test 2: unsigned formulary excecption caught
		// bureaucrat00("Bureaucrat00", toSet);

		// // Test 3: grade to low exception caught 
		// bureaucrat00("Bureaucrat00", toSet);

		// // Test 4: grade exception caught
		// bureaucrat00("Bureaucrat00", toSet);


	} catch (std::exception const & e) {
		std::cout << "Exception caught: [" << e.what() << "]" << std::endl;
	}
}