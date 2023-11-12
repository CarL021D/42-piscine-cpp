#include "includes/RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& src) { _valueStack = src._valueStack; }

RPN& RPN::operator=(const RPN& rhs) {

	_valueStack = rhs._valueStack;	
	return *this;
}

bool RPN::commandLineError(std::string line) {

	if (line.length() < 6) {
		std::cerr << "Error" << std::endl;
		return true;
	}

	for (uint32_t i = 0; i < line.length(); ++i) {

		if (!isdigit(line[i]) && line[i] != '+' && line[i] != '-' && line[i] != '*' && line[i] != '/') {

			std::cerr << "Error" << std::endl;
			return true;
		}

		if (i + 1 >= line.length() || line[i + 1] == ' ')
			i++;
		else {		
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

/*
	if pos == 0
		while (pos != 2; pos += 2)

				push_back if is digit == true
				if stack. size != 2
					error
					return ;
				pos += 2

	if char is sign
		if size == 2
			calcul
		else
			error

	if digit
		if size == 1
			push_back
		else
			error

*/
