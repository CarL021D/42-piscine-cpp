#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& src) { *this = src; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) { 
	static_cast<void>(rhs);	
	return *this;
}


bool ScalarConverter::strIsInt(std::string str) {
	int		nb;
	int 	sign = 1;
	size_t	offset = 0;

	while (str[offset] == '+' || str[offset] == '-') {
		if (str[offset] == '-')
			sign *= -1;
		offset++;
	}
	for (; offset < str.length(); offset++)
		if (!std::isdigit(str[offset]))
			return false;
	for (size_t i = 0; i < str.length(); i++) {
		if (str[i] == '+' || str[i] == '-') {
			str.erase(i, 1);
			i--;
		}
	}
	nb = std::atoi(str.c_str()) * sign;
	if (nb > INT_MAX || nb < INT_MIN) {
		std::cout << "Int overflow" << std::endl;
		return false;
	}
	if (nb >= 32 && nb <= 126)
		std::cout << "char: " << static_cast<char>(nb) << std::endl;
	else
		std::cout << "char: Non printable" << std::endl;
	std::cout << "int: " << nb << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(nb) << "f" << std::endl; 
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(nb) << std::endl;
	return true;
}

bool ScalarConverter::strIsChar(std::string str) {
	char c;
	

	if (str.length() != 1 || str[0] < 32 || str[0] > 126 )
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
	if (!strIsChar(str))
		std::cout << str << " couldn't be converted" << std::endl;
}