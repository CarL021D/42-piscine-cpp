#include "includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& src) { *this = src; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) { 
	static_cast<void>(rhs);	
	return *this;
}

bool ScalarConverter::argumentError(std::string& arg) {

	bool mulitipleDot = false;

	for (uint32_t i = 0; i < arg.size(); ++i) {

		if (arg[0] == '-')
			i++;

		if (isalpha(arg[i]) && i != (arg.size() - 1))
			return true;

		if (arg[i] == 'f' && !mulitipleDot)
			return true;

		if (arg.length() > 1 && !isdigit(arg[i]) && arg[i] != '.' && (arg[i] != 'f' ))
			return true;

		if (arg[i] == '.' && mulitipleDot)
			return true;

		if (arg[i] == '.')
			mulitipleDot = true;
	}
	return false;
}

void ScalarConverter::argIntoFloat(double value) {
	
	std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
}

void ScalarConverter::argIntoInt(double value) {
	
	if (!std::isfinite(value) || value > INT_MAX || value < INT_MIN) {
		std::cout << "int: impossible" << std::endl;
		return ;
	}

	std::cout << "int: " << static_cast<int>(value) << std::endl; 
}

void  ScalarConverter::argIntoChar(double value) {

	char c = static_cast<char>(value);
	std::cout << "double char 			" << value <<std::endl;

	if (!std::isfinite(value) || value > INT_MAX || value < INT_MIN) {
		std::cout << "char: impossible" << std::endl;
		return ;
	}

	std::cout << "char 			[" << c << "]" <<std::endl;

	if (isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: non printable" << std::endl;
}

void ScalarConverter::convert(std::string arg) {
	double  _double;
	
	if (arg.empty() || argumentError(arg)) {
		std::cerr << "Error bad argument" << std::endl;
		return ;
	}

	if (isalpha(arg[0]))
		_double = arg[0];
	else
		_double = std::atof(arg.c_str());

	argIntoChar(_double);
	argIntoInt(_double);
	argIntoFloat(_double);
	std::cout << "double: " << _double << std::endl;	
}