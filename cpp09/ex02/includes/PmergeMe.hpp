#pragma once
#include <iostream>
#include <cstdlib>
#include <stdint.h>
#include <algorithm>
#include <vector>
#include <deque>
#include <utility>
#include <climits>

class PmergeMe {

	public:
			PmergeMe();
			~PmergeMe();
			PmergeMe(const PmergeMe& src);
			PmergeMe& operator=(const PmergeMe& rhs);
	
			bool commandLineError(int32_t ac, char **av);
			void vSort(const std::string& line);

	private:
			std::vector<uint32_t> _vHigherValues;
			std::vector<uint32_t> _vlowerValues;
			std::vector<std::pair<uint32_t, uint32_t> > _vPairs;
			
			std::deque<uint32_t> _deq;
			std::deque<std::pair<uint32_t, uint32_t> > _dPairs;

			bool _oddList;
			uint32_t _remainingVal;

			void vMakePairs(const std::string& line);

};
