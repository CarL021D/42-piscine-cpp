#include "Brain.hpp"

Brain::Brain() { std::cout << "Brain constructor called" << std::endl; }

Brain::~Brain() { std::cout << "Brain destructor called" << std::endl; }

Brain& Brain(const Brain& cpy) { return *this = cpy; }

void Brain::operator=(const Brain& rhs) {

    this->ideas = rhs->ideas;
    return *this;
}