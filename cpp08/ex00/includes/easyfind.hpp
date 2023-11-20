#pragma once
#include <iostream>
#include <stdint.h>
#include <stdexcept>

class NoOccurenceException : public std::exception {
	public:
			const char* what() const throw() {
				return "No Occurrence exception thrown";
			}
};

template <typename T>
void easyFind(const T& container, int32_t value) {
	
	typename T::const_iterator it;

	for (it = container.begin(); it != container.end(); ++it) {
		if (*it == value) {
			std::cout	<< "Occurrence of number: " << value << " found at index "
						<< std::distance(container.begin(), it) << std::endl;
			return;
		}
	}

	throw NoOccurenceException();
}