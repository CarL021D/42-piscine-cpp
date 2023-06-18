#include "includes/Ice.hpp"

Ice::Ice() { std::cout << "Ice constructor called" << std::endl; }

Ice::~Ice() { std::cout << "Ice destructor called" << std::endl; }

Ice::Ice(Ice& const cpy) { *this = cpy; }

Ice& Ice::operator=(Ice& const rhs) { return *this; }

const std::string Ice::getType() { return this->_type; }

Ice* Ice::clone() const { return (new Ice()); }

Ice* Ice::createMateria(std::string type) { 
    if (type != "ice")

    
    /* set Ice into an arr[3] of Ice*/ }

void Ice::use(ICharacter& target) { std::cout << "* shoots an ice bolt at " << target.name << std::endl; }