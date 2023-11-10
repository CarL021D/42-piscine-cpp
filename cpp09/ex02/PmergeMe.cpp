#include "includes/PmergeMe.hpp"

PmergeMe::PmergeMe() : _oddList(false) {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& src) { *this = src; }

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs) {
	(void)rhs;	
	return *this;
}

void PmergeMe::vSort(const std::string& line) {

	clock_t startTime = clock();

	vMakePairs(line);
	for (std::vector<std::pair<uint32_t, uint32_t> >::const_iterator it = _vPairs.begin(); it != _vPairs.end(); ++it)
		_vHighestValues.push_back(it->first);
	vMergeSort(0, _vHighestValues.size() - 1);

	for (std::vector<std::pair<uint32_t, uint32_t> >::const_iterator it = _vPairs.begin(); it != _vPairs.end(); ++it) {
		
		uint32_t n = _vHighestValues.size() - 1;
		uint32_t i = vBinarySearch(it->second, 0, n);		
		_vHighestValues.insert(_vHighestValues.begin() + i, it->second);
	}

	if (_oddList) {

		uint32_t i = vBinarySearch(_remainingVal, 0, _vHighestValues.size() - 1);		
		_vHighestValues.insert(_vHighestValues.begin() + i, _remainingVal);
	}

	clock_t end_time = clock();
	double elapsed_time = static_cast<double>(end_time - startTime) / CLOCKS_PER_SEC * 1e6;
	std::cout.precision(5);


	std::cout << std::endl << "After:	";
	for (std::vector<uint32_t>::const_iterator it = _vHighestValues.begin(); it != _vHighestValues.end(); ++it)
		std::cout << " " << *it;
	std::cout << std::endl;
	std::cout << "Elapsed time: " << std::fixed << elapsed_time << " us" << std::endl;
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

	uint32_t tmp[high];

	for (uint32_t i = low; i <= high; ++i)
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

	uint32_t mid = low + (high - low) / 2;

	if (_vHighestValues.size() == 2) {

		std::cout << "		only 2 values" << std::endl;
		if (target < _vHighestValues.at(mid))
			return mid;
		else if (target < _vHighestValues.at(high))
			return mid += 1;
		return mid += 2;
	}

	if (_vHighestValues.at(mid) == target)
		return mid;
	
	if (low == mid) {

		if (target > _vHighestValues.at(mid))
			return mid + 1;
		return mid;
	}

	if (_vHighestValues.at(mid) > target)
		 return vBinarySearch(target, low, mid);

	return vBinarySearch(target, mid + 1, high);	
}
