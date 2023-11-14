#pragma once
#include <iostream>
#include <cstdlib>
#include <stdint.h>
#include <vector>
#include <deque>
#include <climits>

class PmergeMe {

	public:
			PmergeMe();
			~PmergeMe();
			PmergeMe(const PmergeMe& src);
			PmergeMe& operator=(const PmergeMe& rhs);
	
			void displayVectorValues(std::vector<uint32_t>& vector) const;
			void displayDequeValues(std::deque<uint32_t>& deque) const;

	private:
};

template<typename Container>
std::vector<std::pair<uint32_t, uint32_t> >    makePairs(Container& container, const std::string& line, bool& oddList, uint32_t remainingVal) {

	(void)container;
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

template<typename Container>
void merge(Container& container, uint32_t low, uint32_t mid, uint32_t high) {

	uint32_t tmp[high];

	for (uint32_t i = low; i <= high; ++i)
		tmp[i] = container.at(i);

	uint32_t i = low;
	uint32_t j = mid + 1;
	uint32_t k = low;

	while (i <= mid && j <= high) {
		if (tmp[i] <= tmp[j])
			container.at(k) = tmp[i++];
		else
			container.at(k) = tmp[j++];
		k++;
	}

	while (i <= mid)
		container.at(k++) = tmp[i++];
}

template<typename Container>
void mergeSort(Container& container, uint32_t low, uint32_t high) {

	if (low >= high)
		return ;

	uint32_t mid = low + (high - low) / 2;
	mergeSort(container, low, mid); 
	mergeSort(container, mid + 1, high);
	merge(container, low, mid, high);
}

template<typename Container>
int32_t binarySearch(Container& container, uint32_t target, uint32_t low, uint32_t high) {

	uint32_t mid = low + (high - low) / 2;

	if (container.size() == 2) {

		std::cout << "		only 2 values" << std::endl;
		if (target < container.at(mid))
			return mid;
		else if (target < container.at(high))
			return mid += 1;
		return mid += 2;
	}

	if (container.at(mid) == target)
		return mid;
	
	if (low == mid) {

		if (target > container.at(mid))
			return mid + 1;
		return mid;
	}

	if (container.at(mid) > target)
		 return binarySearch(container, target, low, mid);
	return binarySearch(container, target, mid + 1, high);	
}

template<typename Container>
void sort(const std::string& line, Container& container) {

	bool oddList;
	uint32_t remainingVal = 0;
	clock_t startTime = clock();

	std::vector<std::pair<uint32_t, uint32_t> > pairs = makePairs(container, line, oddList, remainingVal);

	for (std::vector<std::pair<uint32_t, uint32_t> >::const_iterator it = pairs.begin(); it != pairs.end(); ++it)
		container.push_back(it->first);
	mergeSort(container, 0, container.size() - 1);

	for (std::vector<std::pair<uint32_t, uint32_t> >::const_iterator it = pairs.begin(); it != pairs.end(); ++it) {
		
		uint32_t size = container.size() - 1;
		uint32_t i = binarySearch(container, it->second, 0, size);		
		container.insert(container.begin() + i, it->second);
	}

	if (oddList) {

		uint32_t i = binarySearch(container, remainingVal, 0, container.size() - 1);		
		container.insert(container.begin() + i, remainingVal);
	}

	clock_t end_time = clock();
	double elapsed_time = static_cast<double>(end_time - startTime) / CLOCKS_PER_SEC * 1e6;
	std::cout.precision(5);
	std::cout << "Elapsed time: " << std::fixed << elapsed_time << " us" << std::endl;
}
