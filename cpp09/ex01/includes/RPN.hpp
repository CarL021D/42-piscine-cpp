#pragma once
#include <iostream>
#include <stack>
#include <cstdint>

class RPN {

	public:
			RPN(void);
			~RPN(void);
			RPN(const RPN& src);
			RPN& operator=(const RPN& rhs);

			bool commandLineError(int32_t ac, std::string line);
			void displayOPerationResult(std::string& line);

	private:
			std::stack<int32_t> _valueStack;
			std::stack<char> _sign stack;
};
