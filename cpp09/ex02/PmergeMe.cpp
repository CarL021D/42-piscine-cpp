#include "includes/PmergeMe.hpp"

// template<typename Container>
PmergeMe::PmergeMe() {}

// template<typename Container>
PmergeMe::~PmergeMe() {}

// template<typename Container>
PmergeMe::PmergeMe(const PmergeMe& src) { *this = src; }

// template<typename Container>
PmergeMe& PmergeMe::operator=(const PmergeMe& rhs) {
	(void)rhs;	
	return *this;
}
// template<typename Container>
void PmergeMe::displayVectorValues(std::vector<uint32_t>& vector) const {

	std::cout << "After:	";
	for (std::vector<uint32_t>::const_iterator it = vector.begin(); it != vector.end(); ++it)
		std::cout << " " << *it;
	std::cout << std::endl;
}

void PmergeMe::displayDequeValues(std::deque<uint32_t>& deque) const {

	std::cout << "After:	";
	for (std::deque<uint32_t>::const_iterator it = deque.begin(); it != deque.end(); ++it)
		std::cout << " " << *it;
	std::cout << std::endl;
}


// template<typename Container>
// void PmergeMe::sort(const std::string& line, Container& container) {

// 	clock_t startTime = clock();

// 	makePairs(line);

// 	for (std::vector<std::pair<uint32_t, uint32_t> >::const_iterator it = _vPairs.begin(); it != _vPairs.end(); ++it)
// 		container.push_back(it->first);
// 	mergeSort(container, 0, container.size() - 1);

// 	for (std::vector<std::pair<uint32_t, uint32_t> >::const_iterator it = _vPairs.begin(); it != _vPairs.end(); ++it) {
		
// 		uint32_t size = container.size() - 1;
// 		uint32_t i = binarySearch(container, it->second, 0, size);		
// 		container.insert(container.begin() + i, it->second);
// 	}

// 	if (_oddList) {

// 		uint32_t i = binarySearch(container, _remainingVal, 0, container.size() - 1);		
// 		container.insert(container.begin() + i, _remainingVal);
// 	}

// 	clock_t end_time = clock();
// 	double elapsed_time = static_cast<double>(end_time - startTime) / CLOCKS_PER_SEC * 1e6;
// 	std::cout.precision(5);
// 	std::cout << "Elapsed time: " << std::fixed << elapsed_time << " us" << std::endl;
// }


// void    PmergeMe::makePairs(const std::string& line) {

// 	int32_t firstValue = -1;
// 	int32_t secondValue = -1;
// 	uint32_t pos = 0;
// 	uint32_t count = 0;

// 	while (pos < line.length()) {
		
// 		uint32_t startPos = line.find_first_of("0123456789", pos);
// 		std::string::size_type endPos = line.find_first_not_of("0123456789", startPos);
// 		std::string numStr = line.substr(startPos, endPos - startPos);
// 		uint32_t num = static_cast<uint32_t>(std::strtoul(numStr.c_str(), NULL, 10));

//  	 	if (firstValue == -1 && (endPos < line.length()))
//  			firstValue = num;
// 		else if (firstValue != -1)
// 			secondValue = num;
// 		else if (endPos == std::string::npos && !(count % 2)) {
// 			_oddList = true;
// 			_remainingVal = num;
// 		}

// 		if (firstValue != -1 && secondValue != -1) {

// 			if (firstValue < secondValue)
// 				std::swap(firstValue, secondValue);
// 			_vPairs.push_back(std::make_pair(firstValue, secondValue));
// 			firstValue = -1;
// 			secondValue = -1;
// 		}

// 		pos = endPos;
// 		count++;
// 	}

// 	if (count == 1) {
// 		std::cerr << "Error: nothing to store at least 2 numbers are required." << std::endl;
// 		exit(1);
// 	}
// }
// template<typename Container>
// void PmergeMe::mergeSort(Container& container, uint32_t low, uint32_t high) {

// 	if (low >= high)
// 		return ;

// 	uint32_t mid = low + (high - low) / 2;
// 	mergeSort(container, low, mid); 
// 	mergeSort(container, mid + 1, high);
// 	merge(container, low, mid, high);
// }
// template<typename Container>
// void PmergeMe::merge(Container& container, uint32_t low, uint32_t mid, uint32_t high) {

// 	uint32_t tmp[high];

// 	for (uint32_t i = low; i <= high; ++i)
// 		tmp[i] = container.at(i);

// 	uint32_t i = low;
// 	uint32_t j = mid + 1;
// 	uint32_t k = low;

// 	while (i <= mid && j <= high) {
// 		if (tmp[i] <= tmp[j])
// 			container.at(k) = tmp[i++];
// 		else
// 			container.at(k) = tmp[j++];
// 		k++;
// 	}

// 	while (i <= mid)
// 		container.at(k++) = tmp[i++];
// }
// template<typename Container>
// int32_t PmergeMe::binarySearch(Container& container, uint32_t target, uint32_t low, uint32_t high) {

// 	uint32_t mid = low + (high - low) / 2;

// 	if (container.size() == 2) {

// 		std::cout << "		only 2 values" << std::endl;
// 		if (target < container.at(mid))
// 			return mid;
// 		else if (target < container.at(high))
// 			return mid += 1;
// 		return mid += 2;
// 	}

// 	if (container.at(mid) == target)
// 		return mid;
	
// 	if (low == mid) {

// 		if (target > container.at(mid))
// 			return mid + 1;
// 		return mid;
// 	}

// 	if (container.at(mid) > target)
// 		 return binarySearch(container, target, low, mid);

// 	return binarySearch(container, target, mid + 1, high);	
// }
