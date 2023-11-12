#pragma once
#include <iostream>
#include <stack>
#include <stdint.h>

class RPN {

	public:
			RPN(void);
			~RPN(void);
			RPN(const RPN& src);
			RPN& operator=(const RPN& rhs);

			bool commandLineError(std::string line);
			void displayOperationResult(std::string line);

	private:
			std::stack<__int32_t> _valueStack;
			std::stack<char> _signStack;
};
