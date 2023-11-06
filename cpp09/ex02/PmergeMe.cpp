#include "includes/PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& src) { *this = src; }

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs) {
	(void)rhs;	
	return *this;
}

bool PmergeMe::commandLineError(int32_t ac, std::string line) {

	if (ac != 2) {
		std::cerr << "Wrong number of arguments" << std::endl;
		return true;
	}

	for (uint32_t i = 0; i < line.length(); ++i) {

		if (!isdigit(line[i]) && line[i] != ' ') {
			std::cerr << "Error" << std::endl;
			return true;
		}
	}

	return false;
}


void    PmergeMe::vMakePairs(const std::string& line) {

	int32_t firstValue = -1;
	int32_t secondValue = -1;
	uint32_t pos = 0;
	uint32_t count = 0;

	while (pos < line.length()) {
		
		uint32_t startPos = line.find_first_of("0123456789", pos);
		uint32_t endPos = line.find_first_not_of("0123456789", startPos);
		std::string numStr = line.substr(startPos, endPos - startPos);
		uint32_t num = static_cast<uint32_t>(std::strtoul(numStr.c_str(), NULL, 10));

		if (firstValue != -1)
			firstValue = num;
		else if (secondValue != -1 && pos >= line.length())
			secondValue = num;
		else if (endPos == line.length() && !(count % 2))
			_remainingVal = num;

		if (firstValue != -1 && secondValue != -1) {

			_vPairs.push_back(std::make_pair(firstValue, secondValue));
			firstValue = -1;
			secondValue = -1;
		}
		// insertValueinPair()

		pos = endPos;
		count++;
	}
}

