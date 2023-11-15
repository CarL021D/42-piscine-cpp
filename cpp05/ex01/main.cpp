#include "includes/Bureaucrat.hpp"
#include "includes/Form.hpp"

int main() {

	try {

		// Test 1: 
		Bureaucrat bureaucrat00("Bureaucrat00", 2);
		Form form00("Formulary00", 8);

		std::cout << "Form: " << form00;
		std::cout << std::endl;
		form00.beSigned(bureaucrat00);
		bureaucrat00.signForm(form00);

		// // Test 2;
		// Bureaucrat	bureaucrat01("Bureaucrat01", 112);
		// Form		form01("Formulary01", 44);

		// std::cout << std::endl;
		// form01.beSigned(bureaucrat01);
		// bureaucrat01.signForm(form01);

		// // Test 3
		// Form		form02("Formulary02", -1);
		// std::cout << form02;

		// // Test 4
		// Form		form03("Formulary03", 300);
		// std::cout << form03;

	} catch (Bureaucrat::GradeTooHighException& e1) {
		std::cout << "Grade to high exception" << std::endl << e1.what() << std::endl;
	} catch (Bureaucrat::GradeTooLowException& e1) {
		std::cout << "Grade to low exception" << std::endl << e1.what() << std::endl;
	} catch (Form::GradeTooHighException& e2) {
		std::cout << "Grade to high exception" << std::endl << e2.what() << std::endl;
	} catch (Form::GradeTooLowException& e2) {
		std::cout << "Grade to low exception" << std::endl << e2.what() << std::endl;
	}
}