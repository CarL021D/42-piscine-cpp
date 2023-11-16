#include "includes/Bureaucrat.hpp"

int main() {
	
	Bureaucrat* employee1;

	try {
		employee1 = new Bureaucrat("employee1", 1);
		std::cout << *employee1 << std::endl;
		delete employee1;
	} catch (Bureaucrat::GradeTooHighException& e) {
		std::cout << e.what() << std::endl;
		delete employee1;
	} catch (Bureaucrat::GradeTooLowException& e) {
		std::cout << e.what() << std::endl;
		delete employee1;
	}

	std::cout << std::endl << "Upgrade:" << std::endl;
	try {
		employee1 = new Bureaucrat("employee1", 2);
		employee1->upgradeGrade();
		std::cout << *employee1 << std::endl;
		employee1->upgradeGrade();
		delete employee1;
	} catch (Bureaucrat::GradeTooHighException& e) {
		std::cout  << e.what() << std::endl;
		delete employee1;
	} catch (Bureaucrat::GradeTooLowException& e) {
		std::cout << e.what() << std::endl;
		delete employee1;
	}

	std::cout << std::endl << "Demote:" << std::endl;
	try {
		employee1 = new Bureaucrat("employee1", 149);
		employee1->demoteGrade();
		std::cout << *employee1 << std::endl;	
		employee1->demoteGrade();
		delete employee1;
	} catch (Bureaucrat::GradeTooHighException& e) {
		std::cout << "Grade too high" << std::endl << e.what() << std::endl;
		delete employee1;
	} catch (Bureaucrat::GradeTooLowException& e) {
		std::cout << e.what() << std::endl;
		delete employee1;
	}
}