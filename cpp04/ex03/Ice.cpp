#include "includes/Ice.hpp"

Ice::Ice() { std::cout << "Ice constructor called" << std::endl; }

Ice::~Ice() { std::cout << "Ice destructor called" << std::endl; }

Ice::Ice(Ice& const cpy) { *this = cpy; }

Ice& Ice::operator=(Ice& const rhs) { return *this; }
