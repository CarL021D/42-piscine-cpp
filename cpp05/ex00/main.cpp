#include "Bureaucrat.hpp"

int main() {

	Bureaucrat* employee1;

	try {
		employee1 = new Bureaucrat("employee1", 1);
		std::cout << *employee1;
		delete employee1;
	} catch (Bureaucrat::GradeTooHighException& e) {
		std::cout << "Grade to high exception" << std::endl << e.what() << std::endl;
		delete employee1;
		return 1;
	} catch (Bureaucrat::GradeTooLowException& e) {
		std::cout << "Grade to low exception" << std::endl << e.what() << std::endl;
		delete employee1;
		return 1;
	}
}