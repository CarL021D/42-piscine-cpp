#include "includes/Includes.hpp"

Animal::Animal() { std::cout << "Aninmal constructor called" << std::endl; }

Animal::~Animal() { std::cout << "Aninmal destructor called" << std::endl; }

Animal::Animal(const Animal& cpy) { *this = cpy; }

Animal& Animal::operator=(const Animal& rhs) {
	this->_type = rhs._type;
	return *this;
}

std::string Animal::getType() const { return this->_type; }

void Animal::makeSound() const { std::cout << "....." << std::endl; }
