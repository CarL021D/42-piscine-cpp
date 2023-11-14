#include <iostream>
#include <vector>
#include "includes/PmergeMe.hpp"



bool commandLineError(char **av) {

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

	PmergeMe pmerge;

	std::vector<uint32_t> vector;
	std::deque<uint32_t> deque;

	if (ac != 2) {
		std::cerr << "Error: wrong number of arguments." << std::endl;
		return 1;
	}

	if (commandLineError(av))
		return 1;

	std::cout << "before:	" << av[1] << std::endl;

	sort(av[1], vector);
	sort(av[1], deque);

	std::cout << "Vector ";
	pmerge.displayVectorValues(vector);
	std::cout << "Deque  ";
	pmerge.displayDequeValues(deque);
	
	
}