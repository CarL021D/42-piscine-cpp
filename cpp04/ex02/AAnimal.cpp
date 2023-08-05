#include "includes/Includes.hpp"

AAnimal::AAnimal() { std::cout << "Aninmal constructor called" << std::endl; }

AAnimal::~AAnimal() { std::cout << "Aninmal destructor called" << std::endl; }

AAnimal::AAnimal(const AAnimal& cpy) { *this = cpy; }

AAnimal& AAnimal::operator=(const AAnimal& rhs) {
	this->_type = rhs._type;
	return *this;
}

std::string AAnimal::getType() const { return this->_type; }
