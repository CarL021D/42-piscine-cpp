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
	} catch (Bureaucrat::GradeTooLowException& e) {
		std::cout << "Grade to low exception" << std::endl << e.what() << std::endl;
		delete employee1;
	}

	std::cout << std::endl << "Upgrade:" << std::endl;
	try {
		employee1 = new Bureaucrat("employee1", 2);
		employee1->upgradeGrade();
		employee1->upgradeGrade();
		std::cout << employee1->getGrade() << std::endl;
	} catch (Bureaucrat::GradeTooHighException& e) {
		std::cout << "Grade to high exception" << std::endl << e.what() << std::endl;
		std::cout << employee1->getGrade() << std::endl;
		delete employee1;
	} catch (Bureaucrat::GradeTooLowException& e) {
		std::cout << "Grade to low exception" << std::endl << e.what() << std::endl;
		std::cout << employee1->getGrade() << std::endl;
		delete employee1;
	}

	std::cout << std::endl << "Demote:" << std::endl;
	try {
		employee1 = new Bureaucrat("employee1", 149);
		employee1->demoteGrade();
		employee1->demoteGrade();
		std::cout << employee1->getGrade() << std::endl;
	} catch (Bureaucrat::GradeTooHighException& e) {
		std::cout << "Grade to high" << std::endl << e.what() << std::endl;
		std::cout << employee1->getGrade() << std::endl;
		delete employee1;
	} catch (Bureaucrat::GradeTooLowException& e) {
		std::cout << "Grade to low" << std::endl << e.what() << std::endl;
		std::cout << employee1->getGrade() << std::endl;
		delete employee1;
	}
}