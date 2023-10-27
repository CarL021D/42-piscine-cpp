#include "includes/RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& src) { *this = src; }

RPN& RPN::operator=(const RPN& rhs) {
	(void)rhs;	
	return *this;
}

bool RPN::commandLineError(int32_t ac, std::string line) {

	if (ac != 2) {
		std::cerr << "Wrong number of arguments" << std::endl;
		return true;
	}

	for (uint32_t i = 0; i < line.length(); ++i) {

		if (!isdigit(line[i]) && line[i] != '+' && line[i] != '-' && line[i] != '*' && line[i] != '/') {
			std::cerr << "Error" << std::endl;
			return true;
		}

		if (i + 1 >= line.length() || line[i + 1] == ' ') {
			i++;
			continue;
		} else {		
			std::cerr << "Error" << std::endl;
			return true;
		}
	}

	return false;
}

void RPN::displayOPerationResult(std::string& line) {

	uint16_t i = line.length - 1;
	uint16_t j = line.length - 1;
	char sign = '\0';

	while (1) {

		while (i < line.length()) {

			if (isdigit(line[i]) && _stack.size != 2) {
				_stack.pushback(line[i] - 48);
				i += 2;
			}
			else if (!isdigit(line[i]))
				i += 2;
			else
				break ;
		}

		while (j < line.length()) {
			
			if (!isdigit(line[j]) && sign == '\0') {
					sign = static_cast<char>(line[j]);
					j += 2;
					break ;
			}
			j += 2;
		}
	}
}


