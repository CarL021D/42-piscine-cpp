#include "includes/PmergeMe.hpp"

PmergeMe::PmergeMe() : _oddList(false) {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& src) { *this = src; }

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs) {
	(void)rhs;	
	return *this;
}

bool PmergeMe::commandLineError(int32_t ac, char **av) {

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

void PmergeMe::vSort(const std::string& line) {

	vMakePairs(line);
	for (std::vector<std::pair<uint32_t, uint32_t> >::const_iterator it = _vPairs.begin(); it != _vPairs.end(); ++it)
		_vHigherValues.push_back(it->first);

	for (std::vector<uint32_t>::const_iterator it = _vHigherValues.begin(); it != _vHigherValues.end(); ++it)
		std::cout << *it << std::endl;


}

void    PmergeMe::vMakePairs(const std::string& line) {

	int32_t firstValue = -1;
	int32_t secondValue = -1;
	uint32_t pos = 0;
	uint32_t count = 0;

	while (pos < line.length()) {
		
		uint32_t startPos = line.find_first_of("0123456789", pos);
		std::string::size_type endPos = line.find_first_not_of("0123456789", startPos);
		std::string numStr = line.substr(startPos, endPos - startPos);
		uint32_t num = static_cast<uint32_t>(std::strtoul(numStr.c_str(), NULL, 10));

 	 	if (firstValue == -1 && (endPos < line.length()))
 			firstValue = num;
		else if (firstValue != -1)
			secondValue = num;
		else if (endPos == std::string::npos && !(count % 2)) {
			_oddList = true;
			_remainingVal = num;
		}

		if (firstValue != -1 && secondValue != -1) {

			if (firstValue < secondValue)
				std::swap(firstValue, secondValue);
			_vPairs.push_back(std::make_pair(firstValue, secondValue));
			firstValue = -1;
			secondValue = -1;
		}

		pos = endPos;
		count++;
	}

	for (std::vector<std::pair<uint32_t, uint32_t> >::const_iterator it = _vPairs.begin(); it != _vPairs.end(); ++it) {
		std::cout << "Pair: (" << it->first << ", " << it->second << ")" << std::endl;
	}
	std::cout << "remaining odd number: " << _remainingVal << std::endl << std::endl;

}

