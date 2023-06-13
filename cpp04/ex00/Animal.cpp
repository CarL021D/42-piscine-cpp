#include "Animal.hpp"

Animal::Animal() {}

~Animal::Animal() {}

Animal::Animal(const Animal& cpy) { *this = cpy; }

Animal& Animal::operator=(const Animal& rhs) {
	this->type = rhs.type;
	return *this;
}

const void Animal::makeSound() { std::cout "....." << std::endl; }
