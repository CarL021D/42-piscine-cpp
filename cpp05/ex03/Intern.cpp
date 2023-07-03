#include "includes/Intern.hpp"
#include "includes/AForm.hpp"
#include "includes/PresidentialPardonForm.hpp"
#include "includes/AForm.hpp"
#include "includes/AForm.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern& src) { *this = src; }

Intern& operator=(const Intern& src) {}

AForm& Intern::createPresidentPresidentForm() { return new PresidentialPardonForm(); }

AForm& Intern::createRobotomyForm() { return new RobotomyRequestForm(); }

AForm& Intern::createShrubberyForm() { return new ShrubberyCreationForm(); }

AForm& Intern::makeForm(const std::string typeName, const std::string target) {
	std::string inputArr[3] = {"president", "roboto", "shruberry"};
	FunctionPtr functions[3] = {&createPresidentPresidentForm, &createRobotomyForm, &createShrubberyForm};
	
	for (short i = 0; i < 3; i++)
		if (typeName = inputArr[i])
			return functions[i];
}