#include <iostream>
// #include <chrono>
#include "includes/PmergeMe.hpp"

bool commandLineError(int32_t ac, char **av) {

	if (ac != 2) {
		std::cerr << "Error: wrong number of arguments." << std::endl;
		return true;
	}

	std::string line = av[1];
	for (uint32_t i = 0; i < line.length(); ++i) {

		if (!isdigit(line[i]) && line[i] != ' ') {
			std::cerr << "Error: wrong characters in the command line." << std::endl;
			return true;
		}
	}

	return false;
}

int main(int ac, char **av) {

	PmergeMe vectorSort;


	if (commandLineError(ac, av))
		return 1;

	std::cout << "before:	" << av[1] << std::endl;

	vectorSort.vSort(av[1]);
	
}