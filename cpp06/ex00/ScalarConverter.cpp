#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& src) { *this = src; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) { 
	static_cast<void>(rhs);	
	return *this;
}




bool ScalarConverter::strIsChar(std::string str) {
	char c;
	

	if (str.length() != 1 || str[0] < 32 || str[0] > 126 )
		return false;

	c = str[0];

	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c - 48) << std::endl; 
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c - '0') << "f" << std::endl; 
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c - 48) << std::endl;
	return true;
}

void ScalarConverter::convert(std::string str) {
	if (!strIsChar(str))
		std::cout << str << " is couldn't be converted" << std::endl;
}