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
		_vHighestValues.push_back(it->first);

	for (std::vector<uint32_t>::const_iterator it = _vHighestValues.begin(); it != _vHighestValues.end(); ++it)
		std::cout << "vector of pairs: ["<< *it << "]" << std::endl;

	std::cout << std::endl;
	vMergeSort(0, _vHighestValues.size() - 1);

	std::cout << std::endl << "Merge Sort" << std::endl;
	std::cout <<  "Highest Values Sorted" << std::endl;
	for (std::vector<uint32_t>::const_iterator it = _vHighestValues.begin(); it != _vHighestValues.end(); ++it)
		std::cout << "val: [" << *it << "]" << std::endl;
	std::cout << std::endl;


	// int n = sizeof(_vHighestValues) / sizeof(_vHighestValues[0]);
	// std::cout << "size " << n << " == " << _vHighestValues.size() - 1 << std::endl;
	// // uint32_t ret = vBinarySearch(5, 0, n - 1);
	// uint32_t ret = vBinarySearch(5, 0, _vHighestValues.size() - 1);
	// std::cout << "binary search: " << ret << std::endl;

	// _vHighestValues.insert(_vHighestValues.begin() + ret, 5);


	// // uint32_t ret = vBinarySearch(5, 0, _vHighestValues.size() - 1);
	// // std::cout << std::endl << "binary search: [" << ret << "]" << std::endl;

	for (std::vector<std::pair<uint32_t, uint32_t> >::const_iterator it = _vPairs.begin(); it != _vPairs.end(); ++it) {
		
		std::cout << "Pairs(second): [" << it->second << "]" << std::endl;
		
		uint32_t i = vBinarySearch(it->second, 0, _vHighestValues.size() - 1);		
	
		// std::cout << std::endl << "binary search: [" << i << "]" << std::endl;

		_vHighestValues.insert(_vHighestValues.begin() + i, it->second);


		std::cout << std::endl << " Tmp Sorted List:" << std::endl;
		for (std::vector<uint32_t>::const_iterator it = _vHighestValues.begin(); it != _vHighestValues.end(); ++it)
			std::cout << "tmp: [" << *it << "]" << std::endl;

		if (_oddList) {

			uint32_t i = vBinarySearch(_remainingVal, 0, _vHighestValues.size() - 1);		
	
			_vHighestValues.insert(_vHighestValues.begin() + i, _remainingVal);
		}
	}

	std::cout << std::endl << "Sorted List:" << std::endl;
	for (std::vector<uint32_t>::const_iterator it = _vHighestValues.begin(); it != _vHighestValues.end(); ++it)
		std::cout << "	val: [" << *it << "]" << std::endl;
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

	if (count == 1) {
		std::cerr << "Error: nothing to store at least 2 numbers are required." << std::endl;
		exit(1);
	}

	for (std::vector<std::pair<uint32_t, uint32_t> >::const_iterator it = _vPairs.begin(); it != _vPairs.end(); ++it) {
		std::cout << "Pair: (" << it->first << ", " << it->second << ")" << std::endl;
	}
	std::cout << "remaining odd number: " << _remainingVal << std::endl;
}

void PmergeMe::vMergeSort(uint32_t low, uint32_t high) {

	if (low >= high)
		return ;

	uint32_t mid = low + (high - low) / 2;
	vMergeSort(low, mid); 
	vMergeSort(mid + 1, high);
	vMerge(low, mid, high);
}

void PmergeMe::vMerge(uint32_t low, uint32_t mid, uint32_t high) {

	uint32_t tmp[mid];

	for (uint32_t i = low; i <= high; i++)
		tmp[i] = _vHighestValues.at(i);

	uint32_t i = low;
	uint32_t j = mid + 1;
	uint32_t k = low;

	while (i <= mid && j <= high) {
		if (tmp[i] <= tmp[j])
			_vHighestValues.at(k) = tmp[i++];
		else
			_vHighestValues.at(k) = tmp[j++];
		k++;
	}

	while (i <= mid)
		_vHighestValues.at(k++) = tmp[i++];
}

int32_t PmergeMe::vBinarySearch(uint32_t target, uint32_t low, uint32_t high) {

		std::cout << std::endl;
		std::cout << "high " << high << std::endl;
		std::cout << "low " << low << std::endl;
		std::cout << "target " << target << std::endl;


	if (low > high)
		return -1;
	
	uint32_t mid = low + (high - low) / 2;


	std::cout << "size " << _vHighestValues.size() << std::endl;
	std::cout << "mid " << mid << std::endl;
	std::cout << "mid val "<< _vHighestValues.at(mid) << std::endl;
	std::cout << std::endl << "HERE" << std::endl << std::endl;

	if (_vHighestValues.at(mid) == target)
	{
		std::cout << "Found !! target " << _vHighestValues.at(mid) << " mid val " << _vHighestValues.at(mid) << std::endl;
		return mid;
	}

	if (high == mid) {
		std::cout << "high = mid -> [" << high << "] [" << mid << "]" << std::endl;
		std::cout << "target: " << target << " mid: " << _vHighestValues.at(mid) <<std::endl;
		if (target > _vHighestValues.at(mid)) {
			std::cout << "	HIGH !!!!" << std::endl;
			return mid + 1;
		}

		std::cout << "	Low !!!!" << std::endl;
		return mid;
	}

	if (_vHighestValues.at(mid) > target) {

		std::cout << "NOT FOUND !" << std::endl;
		 return vBinarySearch(target, low, mid - 1);
	}

	std::cout << "NOT FOUND !!!!!!" << std::endl;
	return vBinarySearch(target, mid + 1, high);	
}
