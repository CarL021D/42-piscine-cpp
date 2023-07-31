#include "includes/Cat.hpp"

Cat::Cat() : _brain(NULL) {
	std::cout << "Cat constructor called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;	
}

Cat::Cat(const Cat& cpy) { *this = cpy; }

Cat& Cat::operator=(const Cat& rhs ) {
	this->_type = rhs._type;
	this->_brain = rhs._brain;
	return *this;
}

void Cat::makeSound() const { std::cout << "Meow" << std::endl; }

void Cat::displayIdea(short i) const {
	if (i < 1 || i > 100)
		return;
	std::cout << this->_brain->ideas[i - 1] << std::endl;
}
