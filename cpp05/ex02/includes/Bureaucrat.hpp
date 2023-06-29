
#pragma once
#include <iostream>
#include <cstdint>
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

			Bureaucrat(const std::string name, int16_t grade);
			~Bureaucrat();
			Bureaucrat (const Bureaucrat& cpy);
			Bureaucrat& operator=(const Bureaucrat& rhs);

			void 				upgradeGrade();
			void				demoteGrade();
			void				signForm(const AForm& form) const;

			std::string const	getName() const;
			int16_t				getGrade() const;
	private:
			Bureaucrat();
			
			const std::string	_name;
			int16_t				_grade;

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs);