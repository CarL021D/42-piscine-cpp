
#pragma once
#include <iostream>
#include <cstdint>
#include <exception>

class Form {
	public:
			~Form();
			Form(const Form& cpy);
			Form& operator=(const Form& rhs);


			void beSigned(Bureaucrat& bureaucrat);



	private:
			const std::string	_name;
			bool				_isSigned;
			const int16_t		_grade;
			const int16_t		_requiredGrade;
}