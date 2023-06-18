#include "includes/Cure.hpp"

Cure::Cure() { std::cout << "Cure constructor called" << std::endl; }

Cure::~Cure() { std::cout << "Cure destructor called" << std::endl; }

Cure::Cure(Cure& const cpy) { *this = cpy; }

Cure& Cure::operator=(Cure& const rhs) { return *this; }
