#include "includes/Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor called" << std::endl;
	for (short i = 0; i < 100; i++) {
		std::stringstream str;
		str << "code idea number: " << (i + 1);
		this->ideas[i] = str.str();
	}
}

Brain::~Brain() { std::cout << "Brain destructor called" << std::endl; }

Brain::Brain(const Brain& cpy) { *this = cpy; }

Brain& Brain::operator=(const Brain& rhs) {
	if (this == &rhs)
		return *this;

	for (short i = 0; i < 100; i++)
		this->ideas[i] = rhs.ideas[i];
	return *this;
}
