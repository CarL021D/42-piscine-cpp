
#pragma once
#include <iostream>
#include <cstdint>
#include <exception>

class Bureaucrat {
	public:
			class GradeTooHighException : public std::exception {
					public:
							virtual const char* what() const throw() {
								return "Grade too high";
							}
			};

			class GradeTooLowException : public std::exception {
					public:
							virtual const char* what() const throw() {
								return "Grade to low";
							}
			};

			Bureaucrat(const std::string name, int8_t grade);
			~Bureaucrat();
			Bureaucrat (const Bureaucrat& cpy);
			Bureaucrat& operator=(const Bureaucrat& rhs);

			void 				upgradeGrade();
			void				demoteGrade();
			std::string const   getName() const;
			int16_t              getGrade() const;
	private:
			std::string const   _name;
			int16_t              _grade;

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs);