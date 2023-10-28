#include <iostream>
#include "includes/RPN.hpp"

 int main(int ac, char **av) {

	RPN rpn;

	if (!rpn.commandLineError(ac, av[1]))
		rpn.displayOperationResult(av[1]);
}