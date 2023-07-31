#include "includes/Dog.hpp"

Dog::Dog() : _brain(NULL) { 
	std::cout << "Dog constructor called" << std::endl; 
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;	
}

Dog::Dog(const Dog& cpy)
{
    _brain = new Brain();

	for (short i = 0; i < 100; i++)
		this->_brain->ideas[i] = cpy._brain->ideas[i];
	*this = cpy;
}

//shallow copy
// Dog::Dog(const Dog& cpy) {
//     _brain = new Brain();
// 	*this = cpy;
// }

//shallow copy
// Dog& Dog::operator=(const Dog& rhs) {
//     if (this == &rhs)
//         return (*this);
// 	this->_brain = rhs._brain;
//     return *this;
// }

Dog& Dog::operator=(const Dog& rhs) {
    if (this == &rhs) {
		return (*this);
	}

	this->_type = rhs._type;
    delete this->_brain;
    this->_brain = new Brain();
	for (short i = 0; i < 100; i++)
		this->_brain->ideas[i] = rhs.getIdea(i);
	return *this;
}

void Dog::makeSound() const { std::cout << "Bark Bark" << std::endl; }

void Dog::displayIdea(short i) const {
	if (i < 1 || i > 100)
		return;
	std::cout << this->_brain->ideas[i - 1] << std::endl;
}

void Dog::setNewIdea(short i, std::string new_idea) {
	if (i < 1 || i > 100) {
		std::cout << "Range index error" << std::endl;
		return ;
	}
	this->_brain->ideas[i - 1] = new_idea;
}

std::string& Dog::getIdea(short i) const {return this->_brain->ideas[i]; }
