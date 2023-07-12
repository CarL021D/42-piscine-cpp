#include "includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& src) { *this = src; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) { 
	static_cast<void>(rhs);	
	return *this;
}

void ScalarConverter::displaySpecialInputMessage(std::string& str) {
	std::cout	<< "char: impossible" << std::endl
				<< "int: impossible" << std::endl;
		if (str == "-inf" || str == "+inf") {
			std::cout	<< "float: " << str[0] << "inff" << std::endl
						<< "double: " << str[0] << "inf" << std::endl;
		} else {
			std::cout	<< "float: nanf" << std::endl
						<< "double: nan" << std::endl;
		}
}

bool ScalarConverter::strIsDouble(std::string str) {
	double	_double;
	short 	sign = 1;
	size_t	offset = 0;

	if (str == "-inf" || str == "+inf" || str == "nan") {
		displaySpecialInputMessage(str);
		return true;
	}
	while (str[offset] == '+' || str[offset] == '-') {
		if (str[offset] == '-')
			sign *= -1;
		offset++;
	}
	if (str[str.length() - 1] == '.')
		return false;
	for (size_t dotCount = 0; offset < str.length(); offset++) {	
		if (!std::isdigit(str[offset]) && str[offset] != '.')
				return false;
		if (str[offset] == '.')
			dotCount++;
	}
	_double = std::atof(str.c_str()) * sign;
	if (_double > DBL_MAX || _double < DBL_MIN) {
		std::cout << "Double overflow" << std::endl;
		return false;
	}
	if (static_cast<int>(_double) >= 32 && static_cast<int>(_double) <= 126)
		std::cout << "char: " << static_cast<char>(_double) << std::endl;
	else
		std::cout << "char: Non printable" << std::endl;
	std::cout << "int: " << static_cast<int>(_double) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<double>(_double) << "f" << std::endl; 
	std::cout << "double: " << std::fixed << std::setprecision(1) << _double << std::endl;
	return true;
}

bool ScalarConverter::strIsFloat(std::string str) {
	float	_float;
	short 	sign = 1;
	size_t	offset = 0;

	if (str == "-inff" || str == "+inff" || str == "nan") {
		displaySpecialInputMessage(str);
		return true;
	}
	if (str[str.length() - 1] != 'f')
		return false;

	while (str[offset] == '+' || str[offset] == '-') {
		if (str[offset] == '-')
			sign *= -1;
		offset++;
	}
	for (size_t i = 0; i < str.length(); i++) {
		if (str[i] == '+' || str[i] == '-') {
			str.erase(i, 1);
			i--;
		}
	}
	_float = std::atof(str.c_str()) * sign;
	if (_float > FLT_MAX || _float < FLT_MIN) {
		std::cout << "Float overflow" << std::endl;
		return false;
	}
	if (static_cast<int>(_float) >= 32 && static_cast<int>(_float) <= 126)
		std::cout << "char: " << static_cast<char>(_float) << std::endl;
	else
		std::cout << "char: Non printable" << std::endl;
	std::cout << "int: " << static_cast<int>(_float) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << _float << "f" << std::endl; 
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(_float) << std::endl;
	return true;
}


bool ScalarConverter::strIsInt(std::string str) {
	int		_int;
	short 	sign = 1;
	size_t	offset = 0;

	while (str[offset] == '+' || str[offset] == '-') {
		if (str[offset] == '-')
			sign *= -1;
		offset++;
	}
	for (; offset < str.length(); offset++)
		if (!std::isdigit(str[offset])) {
			return false;
		}
	for (size_t i = 0; i < str.length(); i++) {
		if (str[i] == '+' || str[i] == '-') {
			str.erase(i, 1);
			i--;
		}
	}
	_int = std::atoi(str.c_str()) * sign;
	if (_int > INT_MAX || _int < INT_MIN) {
		std::cout << "Int overflow" << std::endl;
		return false;
	}
	if (_int >= 32 && _int <= 126)
		std::cout << "char: " << static_cast<char>(_int) << std::endl;
	else
		std::cout << "char: Non printable" << std::endl;
	std::cout << "int: " << _int << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(_int) << "f" << std::endl; 
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(_int) << std::endl;
	return true;
}

bool ScalarConverter::strIsChar(std::string str) {
	char c;
	
	if (str.length() != 1 || (str[0]) < 32 || (str[0]) > 126 )
		return false;

	c = str[0];
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl; 
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl; 
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
	return true;
}

void ScalarConverter::convert(std::string str) {
	if (str.empty())
		return ;
	if (!strIsChar(str) && !strIsInt(str) && !strIsFloat(str) && !strIsDouble(str))
		std::cout << str << " couldn't be converted" << std::endl;
}