
#pragma once
#include <iostream>
#include <cstdint>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	public:
			class GradeTooHighException : std::exception {
					public:
							virtual const char* what() const throw();
			};

			class GradeTooLowException : std::exception {
					public:
							virtual const char* what() const throw();
			};

			AForm(const std::string& name, const int16_t signGrade, const int16_t _execGrade);
			virtual ~AForm();
			AForm(const AForm& cpy);
			AForm& operator=(const AForm& rhs);

			void			beSigned(Bureaucrat& bureaucrat);
			virtual void	execute(const Bureaucrat& executor) const = 0;

			const std::string	getName() const;
			int16_t				getGrade() const;
			int16_t				getExecGrade() const;
			bool				getIsSigned() const;
			
	private:
					AForm();
	protected:
			const std::string	_name;
			const int16_t		_signGrade;
			const int16_t		_execGrade;
			bool				_isSigned;
};

std::ostream& operator<<(std::ostream& os, const AForm& rhs);