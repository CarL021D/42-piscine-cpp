#include "includes/Bureaucrat.hpp"
#include "includes/Form.hpp"

int main() {

	try {
		Bureaucrat bureaucrat00("Bureaucrat00", 44);
		Form form00("Formulary00", 3);
		std::cout << "Form: " << form00;

		form00.beSigned(bureaucrat00);
		// bureaucrat00.signForm(form00);
	} catch (Bureaucrat::GradeTooHighException& e1) {
		std::cout << "Grade to high exception" << std::endl << e1.what() << std::endl;
	} catch (Bureaucrat::GradeTooLowException& e1) {
		std::cout << "Grade to low exception" << std::endl << e1.what() << std::endl;
	} catch (Form::GradeTooHighException& e2) {
		std::cout << "Grade to high exception" << std::endl << e2.what() << std::endl;
	} catch (Form::GradeTooLowException& e2) {
		std::cout << "Grade to low exception" << std::endl << e2.what() << std::endl;
	}

	// try {
	// 	bureaucrat00 = new Bureaucrat("Bureaucrat00", 100);
	// 	form00 = new Form("Formulary00", 3);

	// 	bureaucrat00->signForm(*form00);
	// 	form00->beSigned(*bureaucrat00);
	// } catch (Bureaucrat::GradeTooHighException& e1) {
	// 	std::cout << "Grade to high exception" << std::endl << e1.what() << std::endl;
	// 	delete	bureaucrat;
	// 	delete form00;
	// } catch (Bureaucrat::GradeTooLowException& e1) {
	// 	std::cout << "Grade to low exception" << std::endl << e1.what() << std::endl;
	// 	delete	bureaucrat;
	// 	delete form00;
	// } catch (Form::GradeTooHighException& e2) {
	// 	std::cout << "Grade to high exception" << std::endl << e2.what() << std::endl;
	// 	delete	bureaucrat;
	// 	delete form00;
	// } catch (Form::GradeTooLowException& e2) {
	// 	std::cout << "Grade to low exception" << std::endl << e2.what() << std::endl;
	// 	delete	bureaucrat;
	// 	delete form00;
	// }



	// try {
	// 	bureaucrat00 = new Bureaucrat("Bureaucrat00", 1);
	// 	form00 = new Form("Formulary00", 1);

	// 	std::cout << "<< Operator:" << std::endl;
	// 	std::cout << *form00;

	// form00->beSigned(*bureaucrat00);
	// bureaucrat00->signForm(*form00);

	// } catch (Bureaucrat::GradeTooHighException& e1) {
	// 	std::cout << "Grade to high exception" << std::endl << e1.what() << std::endl;
	// } catch (Bureaucrat::GradeTooLowException& e1) {
	// 	std::cout << "Grade to low exception" << std::endl << e1.what() << std::endl;
	// } catch (Form::GradeTooHighException& e2) {
	// 	std::cout << "Grade to high exception" << std::endl << e2.what() << std::endl;
	// } catch (Form::GradeTooLowException& e2) {
	// 	std::cout << "Grade to low exception" << std::endl << e2.what() << std::endl;
	// }




	// std::cout << std::endl << "Upgrade:" << std::endl;
	// try {
	// 	employee1 = new Bureaucrat("employee1", 2);
	// 	employee1->upgradeGrade();
	// 	employee1->upgradeGrade();
	// 	std::cout << employee1->getGrade() << std::endl;
	// } catch (Bureaucrat::GradeTooHighException& e) {
	// 	std::cout << "Grade to high exception" << std::endl << e.what() << std::endl;
	// 	std::cout << employee1->getGrade() << std::endl;
	// 	delete employee1;
	// } catch (Bureaucrat::GradeTooLowException& e) {
	// 	std::cout << "Grade to low exception" << std::endl << e.what() << std::endl;
	// 	std::cout << employee1->getGrade() << std::endl;
	// 	delete employee1;
	// }

	// std::cout << std::endl << "Demote:" << std::endl;
	// try {
	// 	employee1 = new Bureaucrat("employee1", 149);
	// 	employee1->demoteGrade();
	// 	employee1->demoteGrade();
	// 	std::cout << employee1->getGrade() << std::endl;
	// } catch (Bureaucrat::GradeTooHighException& e) {
	// 	std::cout << "Grade to high" << std::endl << e.what() << std::endl;
	// 	std::cout << employee1->getGrade() << std::endl;
	// 	delete employee1;
	// } catch (Bureaucrat::GradeTooLowException& e) {
	// 	std::cout << "Grade to low" << std::endl << e.what() << std::endl;
	// 	std::cout << employee1->getGrade() << std::endl;
	// 	delete employee1;
	// }
}