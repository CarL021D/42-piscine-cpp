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

void RPN::displayOperationResult(std::string line) {

	int16_t i = line.length() - 1;

	while (i >= 0) {

		if (isdigit(line[i]))
			_valueStack.push(line[i] - 48);
		else
			_signStack.push(line[i]);
		i -= 2;
	}

	if (_valueStack.size() != _signStack.size() + 1) {
		std::cerr << "Error" << std::endl;
		return ;
	}

	while (1) {

		int32_t res, nb1, nb2;

		nb1 = _valueStack.top();
		_valueStack.pop();
		nb2 = _valueStack.top();
		_valueStack.pop();

		if (_signStack.top() == '+')
			res = nb1 + nb2;
		else if (_signStack.top() == '-')
			res = nb1 - nb2;
		else if (_signStack.top() == '/') {
			if (!nb1 || !nb2) {
				std::cerr << "Error: division by zero." << std::endl;
				return ;
			}
			res = nb1 / nb2;
		} else
			res = nb1 * nb2;

		_signStack.pop();

		if (_valueStack.empty() && _signStack.empty()) {
			std::cout << res << std::endl;
			return ;
		}

		_valueStack.push(res);
	}
}
