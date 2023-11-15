#include "includes/Intern.hpp"
#include "includes/AForm.hpp"
#include "includes/PresidentialPardonForm.hpp"
#include "includes/AForm.hpp"
#include "includes/AForm.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern& src) { *this = src; }

Intern& Intern::operator=(const Intern& rhs) {
	(void)rhs;
	return *this;
}

AForm* Intern::createPresidentForm(const std::string target) { return new PresidentialPardonForm(target); }
AForm* Intern::createRobotomyForm(const std::string target) { return new RobotomyRequestForm(target); }
AForm* Intern::createShrubberyForm(const std::string target) { return new ShrubberyCreationForm(target); }

AForm* Intern::makeForm(const std::string typeName, const std::string target) {
	AForm* form = nullptr;
	std::string formNamesArr[3] = {"president", "roboto", "shruberry"};
	AForm* (Intern::*formTypesArr[3])(const std::string) = {
		&Intern::createPresidentForm,
		&Intern::createRobotomyForm,
		&Intern::createShrubberyForm
	};

	for (short i = 0; i < 3; i++) {
		if (typeName == formNamesArr[i])
		{
			form = (this->*formTypesArr[i])(target);
			std::cout << "Intern creates " << formNamesArr[i] << " form" << std::endl;
			return form;
		}
	}
	std::cout << "Wrong form input name: " << typeName << std::endl;
	return nullptr;
}