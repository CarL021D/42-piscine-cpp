#include "includes/Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor called" << std::endl;
	this->ideas = new std::string[100];
	for (short i = 0; i < 100; i++)
		ideas[i] = "encripted idea: " + std::to_string(i);
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
	delete[] this->ideas;
}

Brain::Brain(const Brain& cpy) { *this = cpy; }

Brain& Brain::operator=(const Brain& rhs) {

	this->ideas = rhs.ideas;
	return *this;
}