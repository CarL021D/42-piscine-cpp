#include "includes/Cat.hpp"

Cat::Cat() {
	std::cout << "Cat constructor called" << std::endl;
	this->_type = "Cat";
	this->brain = new Brain();
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete this->brain;	
}

Cat::Cat(const Cat& cpy) { *this = cpy; }

Cat& Cat::operator=(const Cat& rhs ) {
	this->_type = rhs._type;
	return *this;
}

void Cat::makeSound() const { std::cout << "Meow" << std::endl; }