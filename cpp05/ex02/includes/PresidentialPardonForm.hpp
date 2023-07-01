
#pragma once
#include <iostream> 
#include <exception>
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm {
	public:
			~PresidentialPardonForm();
			PresidentialPardonForm(const PresidentialPardonForm& cpy);
			PresidentialPardonForm(const std::string target);
			PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);

            void	execute(const Bureaucrat& executor) const;
	private:
			PresidentialPardonForm();
			void	printTree(std::ofstream& os) const;

			const std::string	_target;
};
