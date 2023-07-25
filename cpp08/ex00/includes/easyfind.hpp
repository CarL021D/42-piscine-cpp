#pragma once
#include <iostream>
#include <stdexcept>

class NoOccurenceException : public std::exception {
	public:
			const char* what() const throw() {
				return "No Occurrence exception thrown";
			}
};

template <typename T>
void easyFind(const T& container, int nb) {
	typename T::const_iterator it;

	for (it = container.begin(); it != container.end(); ++it) {
		if (*it == nb) {
			std::cout << "Occurrence of number: " << nb << " found at index " << std::distance(container.begin(), it) << std::endl;
			return;
		}
	}
	throw NoOcccurenceException();
}