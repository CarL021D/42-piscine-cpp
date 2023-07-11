#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "ScalarConverter.hpp"

int main(int ac, char **av) {
	std::string input;
	
	if (ac != 2) {
		std::cout << "2 arguments are required" << std::endl;
		return 1;
	}
	input = av[1];
	ScalarConverter::convert(input);
}