#include "includes/Span.hpp"

Span::Span() {}

Span::~Span() {}

Span::Span(uint32_t sizeMax) {
	
	if (!std::isfinite(_sizeMax) || _sizeMax > INT_MAX || _sizeMax < 0)
		throw IndexErrorException();
	_sizeMax = sizeMax;
}

Span::Span(const Span& src) {
	
	if (src._sizeMax > INT_MAX || src._sizeMax < INT_MIN)
		throw IndexErrorException();

	_vec = src._vec;
	_sizeMax = src._sizeMax;

	for (std::vector<int>::const_iterator it = src._vec.begin(); it != src._vec.end(); ++it)
		_vec.push_back(*it);
	*this = src;
}

Span& Span::operator=(const Span& rhs) {
	
	if (rhs._sizeMax > INT_MAX || rhs._sizeMax < INT_MIN)
		throw IndexErrorException();

	_vec = rhs._vec;
	_sizeMax = rhs._sizeMax;

	for (std::vector<int>::const_iterator it = rhs._vec.begin(); it != rhs._vec.end(); ++it)
		_vec.push_back(*it);
	return *this;
}

void	Span::addNumber(int32_t nbr) {

	if (nbr > INT_MAX || nbr < INT_MIN)
		return ;

	_vec.push_back(nbr);
}

int	Span::longestSpan() const {

	if (_sizeMax < 2)
		throw IndexErrorException();
	int maxRange = std::numeric_limits<int>::min();
	for (uint32_t i = 0; i < _vec.size() - 1; i++) {
		for (uint32_t j = i + 1; j < _vec.size(); j++) {
			int range = std::abs(_vec[j] - _vec[i]);
			maxRange = std::max(maxRange, range);
		}
	}
	return maxRange;
}

int	Span::shortestSpan() const {
	if (_sizeMax < 2)
		throw IndexErrorException();
	
	int minRange = std::numeric_limits<int>::max();
	for (uint32_t i = 0; i < _vec.size() - 1; i++) {
		for (uint32_t j = i + 1; j < _vec.size(); j++) {
			int range = std::abs(_vec[j] - _vec[i]);
			minRange = std::min(minRange, range);
		}
	}
	return minRange;
}

int Span::begin() const {
	if (_sizeMax < 1)
		throw IndexErrorException();
	return _vec[0];	
}

int Span::end() const {
	if (_sizeMax < 1)
		throw IndexErrorException();
	return _vec.back();	
}

void Span::printContent() const {

	if (!_vec.size()) {
		std::cout << "Empty array" << std::endl;
		return ;
	}

	std::cout << "List:";
	for (std::vector<int>::const_iterator it = _vec.begin(); it != _vec.end(); ++it)
		std::cout << " " << *it << " ";
	std::cout << std::endl;
}