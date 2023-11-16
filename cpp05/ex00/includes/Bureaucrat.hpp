
#pragma once
#include <iostream>
#include <stdint.h>
#include <exception>

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
			const std::string	getName() const;
			int16_t				getGrade() const;
	private:
			Bureaucrat();
			
			const std::string	_name;
			int16_t			_grade;
			
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs);