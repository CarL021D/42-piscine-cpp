
#pragma once
#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
	public:
			class GradeTooHighException : public std::exception {
					public:
							virtual const char* what() const throw();
			};

			class GradeTooLowException : public std::exception {
					public:
							virtual const char* what() const throw();
			};

			class UnsignedFormularyException : std::exception {
				public:
						virtual const char* what() const throw();
			};

			Bureaucrat(const std::string name, short grade);
			~Bureaucrat();
			Bureaucrat (const Bureaucrat& src);
			Bureaucrat& operator=(const Bureaucrat& rhs);

			void	upgradeGrade();
			void	demoteGrade();
			void	signForm(const AForm& form) const;
			void	executeForm(const AForm& form);


			const std::string	getName() const;
			short				getGrade() const;
	private:
			Bureaucrat();

			const std::string	_name;
			short				_grade;

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs);