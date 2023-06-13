#include "Dog.hpp"

Dog::Dog() {}

~Dog::Dog() {}

Dog::Dog(const Dog& cpy) { return *this->cpy; }

Dog& Dog::operator=(const Dog& rsh) {
    this->type = rhs->type;
    return *this;
}

void Dog::makeSound() { std::cout << "Bark Bark" << std::endl; }