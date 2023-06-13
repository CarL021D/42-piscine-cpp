#include "Animal.hpp"

Animal::Animal() {}

~Animal::Animal() {}

Animal::Animal(const Animal& cpy) { *this = cpy; }

Animal& Animal::operator=(const Animal& rhs) {
	this->type = rhs.type;
	return *this;
}

std::string Animal::getType() { return this->type; }

const void Animal::makeSound() { std::cout "....." << std::endl; }
