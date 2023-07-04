#pragma once
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
	public:
			Intern();
			~Intern();
			Intern(const Intern& src);
			Intern& operator=(const Intern& rhs);

			AForm*	makeForm(const std::string typeName, const std::string target);
	private:
			typedef AForm* (Intern::*FunctionPtr)(const std::string);

			AForm*	createPresidentForm(const std::string target);
			AForm*	createRobotomyForm(const std::string target);
			AForm*	createShrubberyForm(const std::string target);
};