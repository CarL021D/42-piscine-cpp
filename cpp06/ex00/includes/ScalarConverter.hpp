#pragma once
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <climits>
#include <cmath>
#include <cfloat>
#include <regex>
#include "includes/ScalarConverter.hpp"


class  ScalarConverter {
	public:
			ScalarConverter();
			~ScalarConverter();
			ScalarConverter(const ScalarConverter& src);
			ScalarConverter& operator=(const ScalarConverter& rhs);

			static void		convert(std::string str);

	private:
			static bool		argumentError(std::string& arg);
			static void		argIntoChar(double value);
			static void		argIntoInt(double value);
			static void		argIntoFloat(double value);
			static bool		argIntoDouble(std::string str);
			static bool		specialAttribut(std::string str);
};