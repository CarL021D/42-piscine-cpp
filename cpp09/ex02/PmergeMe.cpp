#include "includes/PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& src) { *this = src; }

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs) {
	(void)rhs;	
	return *this;
}

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
