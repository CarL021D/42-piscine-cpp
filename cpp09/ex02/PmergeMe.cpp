#include "includes/PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& src) { *this = src; }

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs) { return *this; }

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

	for (uint32_t  pos = 0; pos < line.length()) {

		size_t startPos = str.find_first_of("0123456789", pos);
		
		if (startPos == std::string::npos) {
			std::cerr << "Error: nothing to sort" << std::endl;
			return  true;
		}


		// size_t startPos = str.find_first_of("0123456789", pos);

		size_t endPos = str.find_first_not_of("0123456789", startPos);

		std::string numStr = str.substr(startPos, endPos - startPos);

	   uint32_t num = static_cast<unsigned int>(std::strtoul(numStr.c_str(), NULL, 10));

		if (num > INT_MAX) {
			std::cerr << "Error: number out of range" << std::endl;
			return true; // The number is greater than UINT_MAX
		}

		// insertValueinPair()

		pos = endPos;
	}

	return false;
}


void    PmergeMe::vMakePairs(const std::string& line) {

	for (uint32_t  pos = 0; pos < line.length()) {

		uint32_t startPos = str.find_first_of("0123456789", pos);
		uint32_t endPos = str.find_first_not_of("0123456789", startPos);
		std::string numStr = str.substr(startPos, endPos - startPos);
		uint32_t num = static_cast<uint32_t>(std::strtoul(numStr.c_str(), NULL, 10));

		

		// insertValueinPair()

		pos = endPos;
	}

	return false;
}

uint32_t PmergeMe::stringIntoUInt(const std::string& str) const {
	char* end;
	const char* cstr = str.c_str();
	uint32_t result = std::strtoul(cstr, &end, 10);

	if (*end != '\0') {
		return 0;
	}

	return static_cast<uint32_t>(result);
}
