
#pragma once
#include <iostream>
#include <cstdint>
#include <exception>
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm {
	public:
			class GradeTooHighException : std::exception {
				public:
						virtual const char* what() const throw();
			};

			class GradeTooLowException : std::exception {
				public:
						virtual const char* what() const throw();
			};

			class UnsignedFormulary : std::exception {
				public:
						virtual const char* what() const throw();
			};

			~ShrubberyCreationForm();
			ShrubberyCreationForm(const ShrubberyCreationForm& cpy);
			ShrubberyCreationForm(const std::string target);
			ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);

			void	beSigned(Bureaucrat& bureaucrat);
            void	execute(const Bureaucrat& executor) const;
	private:
			ShrubberyCreationForm();
};