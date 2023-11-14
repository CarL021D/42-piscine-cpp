#include "includes/RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& src) { _valueStack = src._valueStack; }

RPN& RPN::operator=(const RPN& rhs) {

	_valueStack = rhs._valueStack;	
	return *this;
}

bool RPN::commandLineError(std::string line) {

	if (line.length() < 5 || !isdigit(line[0])) {
		std::cerr << "Error." << std::endl;
		return true;
	}

	for (uint32_t i = 0; i < line.length(); ++i) {

		if (!isdigit(line[i]) && line[i] != '+' && line[i] != '-' && line[i] != '*' && line[i] != '/') {

			std::cerr << "Error." << std::endl;
			return true;
		}

		if (i + 1 >= line.length() || line[i + 1] == ' ')
			i++;
		else {		
			std::cerr << "Error." << std::endl;
			return true;
		}
	}

	return false;
}

void RPN::displayOperationResult(std::string line) {

	int32_t res, nb1, nb2;;

	_valueStack.push(line[0] - 48);
	for (uint32_t pos = 2; pos < line.length(); pos += 2) {

		if (!isdigit(line[pos])) {

			if (_valueStack.size() >= 2) {

				nb1 = _valueStack.top();
				_valueStack.pop();
				nb2 = _valueStack.top();
				_valueStack.pop();


				if (line[pos] == '+')
					res = nb2 + nb1;
				else if (line[pos] == '-')
					res = nb2 - nb1;
				else if (line[pos] == '/') {
					if (!nb1 || !nb2) {
						std::cerr << "Error: division by zero." << std::endl;
						return ;
					}
					res = nb2 / nb1;
				} else
					res = nb2 * nb1;

				_valueStack.push(res);
			}
			else {

				std::cerr << "Error." << std::endl;
				return ;
			}
		} else
			_valueStack.push(line[pos] - 48);
	}

	if (_valueStack.size() != 1)
		std::cerr << "Error." << std::endl;
	else
		std::cout << res << std::endl;
}
