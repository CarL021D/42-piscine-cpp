#pragma once
#include <iostream>
#include <stdint.h>
#include <algorithm>
#include <stdexcept>

class NoOccurenceException : public std::exception {
	public:
			const char* what() const throw() {
				return "No Occurrence exception thrown";
			}
};

template <typename T>
void easyFind(const T& container, int32_t value) {

	typename T::const_iterator it = std::find(container.begin(), container.end(), value);
	if (it != container.end()) {
		std::cout	<< "Occurrence of number: " << value << " found at index "
					<< std::distance(container.begin(), it) << std::endl;
		return ;
	}

	throw NoOccurenceException();
}