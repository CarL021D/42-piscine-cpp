#include "Bureaucrat.hpp"

int main() {

	Bureaucrat* employee1;

	try {
		employee1 = new Bureaucrat("employee1", 2);
		std::cout << employee1 << std::endl;
	} catch (Bureaucrat::GradeTooHighException& e) {
		std::cout << "Grade to high execption" << e.what() << std::endl;
	} catch (Bureaucrat::GradeTooLowException& e) {
		std::cout << "Grade to low execption" << e.what() << std::endl;
	}
}