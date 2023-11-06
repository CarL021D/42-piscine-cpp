#pragma once
#include <iostream>
#include <stdint.h>
#include <vector>
#include <deque>
#include <pair>
#include <climits>

class PmergeMe {

	public:
			PmergeMe();
			~PmergeMe();
			PmergeMe(const PmergeMe& src);
			PmergeMe& operator=(const PmergeMe& rhs);
	
			bool commandLineError(int32_t ac, std::string line);

	private:
			std::vector<uint32_t> _vec;
			std::vector<std::pair> _vPairs;
			
			std::deque<uint32_t> _deq;
			std::deque<std::pair<uint32_t, uint32_t>> _dPairs;
};
