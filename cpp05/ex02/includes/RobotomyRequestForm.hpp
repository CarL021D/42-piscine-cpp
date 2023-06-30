
#pragma once
#include <iostream>
#include <cstdint>
#include <exception>
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm {
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
			}

			~RobotomyRequestForm();
			RobotomyRequestForm(const RobotomyRequestForm& cpy);
			RobotomyRequestForm(const std::string target);
			RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);

			void	beSigned(Bureaucrat& bureaucrat);
            void	execute(const Bureaucrat& executor) const;
	private:
			RobotomyRequestForm();
};