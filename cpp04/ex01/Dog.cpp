#include "includes/Dog.hpp"

Dog::Dog() { 
	std::cout << "Dog constructor called" << std::endl; 
	this->_type = "Dog";
	this->brain = new Brain();
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain;	
}

Dog::Dog(const Dog& cpy) { *this = cpy; }

Dog& Dog::operator=(const Dog& rhs) {
	this->_type = rhs._type;
	return *this;
}

void Dog::makeSound() const { std::cout << "Bark Bark" << std::endl; }

void Dog::displayIdea(short i) const {
	if (i < 1 || i > 100)
		return;
	std::cout << this->brain->ideas[i - 1] << std::endl;
}

// void	Dog::setIdea(short i, std::string idea) { this->brain.ideas[i] = idea; }
