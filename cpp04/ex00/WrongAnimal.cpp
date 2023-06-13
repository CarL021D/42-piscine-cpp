#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() { std::cout << "Wrong aninmal constructor called" << std::endl; }

WrongAnimal::~WrongAnimal() { std::cout << "Wrong aninmal destructor called" << std::endl; }

WrongAnimal::WrongAnimal(const WrongAnimal& cpy) { *this = cpy; }

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs) {
	this->_type = rhs._type;
	return *this;
}
std::string WrongAnimal::getType() { return this->_type; }

void	WrongAnimal::makeSound() const { std::cout << "..." << std::endl; }