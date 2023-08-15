#include "includes/Span.hpp"

Span::Span() {}

Span::~Span() {}

Span::Span(size_t sizeMax) : _sizeMax(sizeMax) {}

Span::Span(const Span& src) { *this = src; }

Span& Span::operator=(const Span& rhs) {
	(void)rhs;
	// _sizeMax = rhs._sizeMax;	
	return *this;
}

void	Span::addNumber(int nbr) {
	if (_vec.size() == _sizeMax)
		throw IndexErrorException();
	_vec.push_back(nbr);
}

int	Span::longestSpan() {
	if (_sizeMax < 2)
		throw IndexErrorException();
	int maxRange = std::numeric_limits<int>::min();
	for (size_t i = 0; i < _vec.size() - 1; i++) {
		for (size_t j = i + 1; j < _vec.size(); j++) {
			int range = std::abs(_vec[j] - _vec[i]);
			maxRange = std::max(maxRange, range);
		}
	}
	return maxRange;
}

int	Span::shortestSpan() {
	if (_sizeMax < 2)
		throw IndexErrorException();
	int minRange = std::numeric_limits<int>::max();
	for (size_t i = 0; i < _vec.size() - 1; i++) {
		for (size_t j = i + 1; j < _vec.size(); j++) {
			int range = std::abs(_vec[j] - _vec[i]);
			minRange = std::min(minRange, range);
		}
	}
	return minRange;
}
