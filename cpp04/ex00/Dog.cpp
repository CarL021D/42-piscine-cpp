#include "Dog.hpp"

Dog::Dog() { 
	std::cout << "Dog constructor called" << std::endl; 
	this->_type = "Dog";
}

Dog::~Dog() { std::cout << "Dog destructor called" << std::endl; }

Dog::Dog(const Dog& cpy) { *this = cpy; }

Dog& Dog::operator=(const Dog& rhs) {
	this->_type = rhs._type;
	return *this;
}

void Dog::makeSound() const { std::cout << "Bark Bark" << std::endl; }