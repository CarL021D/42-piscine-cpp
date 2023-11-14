#include <iostream>
#include <vector>
#include <deque>

#include <stdint.h>


std::vector<std::pair<uint32_t, uint32_t> >    makePairs(const std::string& line, bool& oddList, uint32_t remainingVal) {

	std::vector<std::pair<uint32_t, uint32_t> > pairs;
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
			oddList = true;
			remainingVal = num;
		}

		if (firstValue != -1 && secondValue != -1) {

			if (firstValue < secondValue)
				std::swap(firstValue, secondValue);
			pairs.push_back(std::make_pair(firstValue, secondValue));
			firstValue = -1;
			secondValue = -1;
		}

		pos = endPos;
		count++;
	}

	if (count == 1) {
		std::cerr << "Error: nothing to store at least 2 numbers are required." << std::endl;
		exit(1);
	}
	(void)remainingVal;
	return pairs;
}
