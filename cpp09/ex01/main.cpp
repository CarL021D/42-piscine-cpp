#include <iostream>
#include "includes/RPN.hpp"

 int main(int ac, char **av) {

	RPN rpn;

	if (rpn.commandLineError(ac, av[1])) {

		std::cout << "failure" << std::endl;
		std::cout << '2' - 48 << std::endl;
	}
	else
		std::cout << "success" << std::endl;

}