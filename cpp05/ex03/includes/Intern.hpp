#pragma once
#include "AForm.hpp"

class Intern {
	public:
			Intern();
			~Intern();
			Intern(const Intern& src);
			Intern& operator=(const Intern& rhs);

			AForm&	makeForm(const std::string typeName, const std::string target);
	private:

}