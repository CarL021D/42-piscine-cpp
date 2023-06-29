
#pragma once
#include <iostream>
#include <cstdint>
#include <exception>
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm {
	public:
			class GradeTooHighException : std::exception {
				public:
						virtual const char* what() const throw();
			};

			class GradeTooLowException : std::exception {
				public:
						virtual const char* what() const throw();
			};

			class FormularynotSignedException : std::exception {
				public:
						virtual const char* what() const throw();
			}

			PresidentialPardonForm();
			~PresidentialPardonForm();
			PresidentialPardonForm(const PresidentialPardonForm& cpy);
			PresidentialPardonForm(const std::string target);
			PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);

			void	beSigned(Bureaucrat& bureaucrat);
            void	execute(const Bureaucrat& executor) const;
};