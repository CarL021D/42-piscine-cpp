
#pragma once
#include <iostream>
#include <cstdint>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	public:
			class GradeTooHighException : std::exception {
					public:
							virtual const char* what() const throw();
			};

			class GradeTooLowException : std::exception {
					public:
							virtual const char* what() const throw();
			};

			Form(const std::string& name, const int16_t grade);
			~Form();
			Form(const Form& cpy);
			Form& operator=(const Form& rhs);

			void beSigned(Bureaucrat& bureaucrat);

			const std::string	getName() const;
			int16_t				getGrade() const;
			int16_t				getExecGrade() const;
			bool				getIsSigned() const;
	private:
			const std::string	_name;
			const int16_t		_grade;
			const int16_t		_execGrade;
			bool				_isSigned;

			Form();
};

std::ostream& operator<<(std::ostream& os, const Form& rhs);