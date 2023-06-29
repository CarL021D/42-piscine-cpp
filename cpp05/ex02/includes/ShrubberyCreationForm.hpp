#pragma once
#include <iostream>
#include <cstdint>
#include <exception>
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public Aform {
	public:
			class GradeTooHighException : std::exception {
					public:
							virtual const char* what() const throw();
			};

			class GradeTooLowException : std::exception {
					public:
							virtual const char* what() const throw();
			};

			ShrubberyCreationForm();
			~ShrubberyCreationForm();
			ShrubberyCreationForm(const ShrubberyCreationForm& cpy);
			ShrubberyCreationForm(const std::string target);
			ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);

			void	execute(const Bureaucrat& executor) const;
	private:
			const std::string	_name;
			const int16_t		_signGrade;
			const int16_t		_execGrade;
			bool				_isSigned;
			const std::string	_target;
}