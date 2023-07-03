
#pragma once
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	public:
			class GradeTooHighException : std::exception {
				public:
						virtual const char* 	what() const throw();
			};

			class GradeTooLowException : std::exception {
				public:
						virtual const char* 	what() const throw();
			};

			class UnsignedFormularyException : std::exception {
				public:
						virtual const char*		what() const throw();
			};

			AForm();
			AForm(const std::string& name, const short signGrade, const short _execGrade);
			virtual ~AForm();
			AForm(const AForm& src);
			AForm& operator=(const AForm& rhs);

			void			beSigned(Bureaucrat& bureaucrat);
			virtual void	execute(const Bureaucrat& executor) const = 0;

			const std::string	getName() const;
			short				getGrade() const;
			short				getExecGrade() const;
			bool				getIsSigned() const;
	protected:
			const std::string	_name;
			const short			_signGrade;
			const short			_execGrade;
			bool				_isSigned;
};

std::ostream& operator<<(std::ostream& os, const AForm& rhs);