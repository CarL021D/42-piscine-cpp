#include "includes/Span.hpp"

Span::Span() {}

Span::~Span() {}

Span::Span(int32_t sizeMax) : _size(0) {
	
	if (!std::isfinite(sizeMax) || sizeMax > INT_MAX || sizeMax < 0)
		throw IndexErrorException();
	_sizeMax = sizeMax;
}

Span::Span(const Span& src) {
	
	if (src._sizeMax > INT_MAX || src._sizeMax < INT_MIN)
		throw IndexErrorException();

	_vec = src._vec;
	_sizeMax = src._sizeMax;
	_size = src._size;

	for (std::vector<int>::const_iterator it = src._vec.begin(); it != src._vec.end(); ++it)
		_vec.push_back(*it);
	*this = src;
}

Span& Span::operator=(const Span& rhs) {
	
	if (rhs._sizeMax > INT_MAX || rhs._sizeMax < INT_MIN)
		throw IndexErrorException();

	_vec = rhs._vec;
	_sizeMax = rhs._sizeMax;
	_size = rhs._size;

	for (std::vector<int>::const_iterator it = rhs._vec.begin(); it != rhs._vec.end(); ++it)
		_vec.push_back(*it);
	return *this;
}

void	Span::addNumber(int32_t nbr) {

	if (nbr > INT_MAX || nbr < INT_MIN || _size == _sizeMax)
		throw IndexErrorException();

	_vec.push_back(nbr);
	_size++;
}

int	Span::longestSpan() const {

	std::vector<int32_t> tmp;
	int32_t min, max;


	if (_sizeMax < 2 || _size < 2)
		throw IndexErrorException();

	tmp = _vec;
	std::sort(tmp.begin(), tmp.end());

	min = tmp.at(0);
	max = tmp.at(1);

	for (std::vector<int32_t>::const_iterator it = tmp.begin() + 2; it != tmp.end(); ++it) {

		if (*it > max) { max = *it; }
		if (*it < min) { min = *it; }
	}

	return max - min;
}

int	Span::shortestSpan() const {
	
	std::vector<int32_t>	tmp;
	int32_t					shortestRange;

	if (_sizeMax < 2 || _size < 2)
		throw IndexErrorException();

	tmp = _vec;

	std::sort(tmp.begin(), tmp.end());
	shortestRange = tmp.at(1) - tmp.at(0);

	for (std::vector<int32_t>::const_iterator it = tmp.begin() + 2; it != tmp.end(); ++it) {

		std::vector<int32_t>::const_iterator tmpIt = it;
		--tmpIt;		
		if ((*it - *tmpIt) < (shortestRange))
			shortestRange = *it - *tmpIt;
	}

	return shortestRange;
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

	std::cout << "Element(s):";
	for (std::vector<int>::const_iterator it = _vec.begin(); it != _vec.end(); ++it)
		std::cout << " " << *it << " ";
	std::cout << std::endl;
}

void	Span::addRandomNbrs(uint32_t count) {

	std::vector<int32_t> tmp;

	if (count < 1)
		return ;

	for (uint32_t i = 0; i < count; ++i) {

		int32_t nb = rand();
		tmp.push_back(nb);
	}

	_vec.insert(_vec.end(), tmp.begin(), tmp.end());
	_size += count;
}
