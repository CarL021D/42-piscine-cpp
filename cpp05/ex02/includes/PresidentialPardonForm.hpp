
#pragma once
#include <iostream> 
#include <exception>
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm {
	public:
			~PresidentialPardonForm();
			PresidentialPardonForm(const PresidentialPardonForm& src);
			PresidentialPardonForm(const std::string target);
			PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);

            void	execute(const Bureaucrat& executor) const;
	private:
			PresidentialPardonForm();
};

std::ostream& operator<<(std::ostream& os, const AForm& rhs);
