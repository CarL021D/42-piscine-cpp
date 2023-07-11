#pragma once
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <climits>
#include "ScalarConverter.hpp"


class  ScalarConverter {
	public:
			ScalarConverter();
			~ScalarConverter();
			ScalarConverter(const ScalarConverter& src);
			ScalarConverter& operator=(const ScalarConverter& rhs);

			static void		convert(std::string str);

	private:
			static bool		strIsChar(std::string str);
			static bool		strIsInt(std::string str);
			static bool		strIsFloat(std::string str);
};