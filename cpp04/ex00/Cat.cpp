#include "Cat.hpp"

Cat::Cat() {}

~Cat::Cat() {}

Cat::Cat(const Cat& cpy) { *this = cpy; }

Cat& Cat::operator=(const Cat& rhs ) {
    this->type = rhs.type;
    return *this;
}

void Cat::makeSound() { std::coouot << "Meow" << std::endl; }