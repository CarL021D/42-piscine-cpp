#include "includes/Includes.hpp"

IAnimal::IAnimal() { std::cout << "Aninmal constructor called" << std::endl; }

IAnimal::~IAnimal() { std::cout << "Aninmal destructor called" << std::endl; }

IAnimal::IAnimal(const IAnimal& cpy) { *this = cpy; }

IAnimal& IAnimal::operator=(const IAnimal& rhs) {
	this->_type = rhs._type;
	return *this;
}

std::string IAnimal::getType() const { return this->_type; }

void IAnimal::makeSound() const { std::cout << "....." << std::endl; }
