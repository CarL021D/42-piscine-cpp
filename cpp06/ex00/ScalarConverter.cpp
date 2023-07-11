#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& src) { *this = src; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) { 
	static_cast<void>(rhs);	
	return *this;
}

bool ScalarConverter::strIsFloat(std::string str) {
	float	_float;
	short 	sign = 1;
	size_t	offset = 0;

	while (str[offset] == '+' || str[offset] == '-') {
		if (str[offset] == '-')
			sign *= -1;
		offset++;
	}
	if (str[str.length() - 1] == '.' || str[str.length() - 1] != 'f')
		return false;
	for (size_t dotCount = 0; offset < str.length(); offset++) {	
		if (!std::isdigit(str[offset]) && str[offset] != '.'
		&& dotCount == 2)
			return false;
		if (str[offset] == '.')
			dotCount++;
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
	
	if (str.length() != 1 || (str[0] - 48) < 32 || (str[0] + 48) > 126 )
		return false;

	c = str[0];
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c - 48) << std::endl; 
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c - 48) << "f" << std::endl; 
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c - 48) << std::endl;
	return true;
}

void ScalarConverter::convert(std::string str) {
	if (str.empty())
		return ;
	if (!strIsChar(str) && !strIsInt(str)&& !strIsFloat(str))
		std::cout << str << " couldn't be converted" << std::endl;
}