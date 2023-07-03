
#pragma once
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm {
	public:
			~RobotomyRequestForm();
			RobotomyRequestForm(const RobotomyRequestForm& src);
			RobotomyRequestForm(const std::string target);
			RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);

            void	execute(const Bureaucrat& executor) const;
	private:
			RobotomyRequestForm();
			
			const std::string	_target;
};

std::ostream& operator<<(std::ostream& os, const AForm& rhs);
