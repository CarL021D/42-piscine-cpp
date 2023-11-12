#include <iostream>
#include "includes/RPN.hpp"

 int main(int ac, char **av) {

	RPN rpn;

	if (ac != 2) {
		std::cerr << "Wrong number of arguments" << std::endl;
		return 1;
	}

	if (!rpn.commandLineError(av[1]))
		rpn.displayOperationResult(av[1]);
}