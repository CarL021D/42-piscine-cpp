#include "Bureaucrat.hpp"

int main() {

	Bureaucrat* employee1;

	try {
		employee1 = new Bureaucrat("employee1", 0);
		std::cout << *employee1 << std::endl;
		delete employee1;
	} catch (Bureaucrat::GradeTooHighException& e) {
		std::cout << "Grade to high execption" << e.what() << std::endl;
		return 1;
	} catch (Bureaucrat::GradeTooLowException& e) {
		std::cout << "Grade to low execption" << e.what() << std::endl;
		return 1;
	}
	delete employee1;
}