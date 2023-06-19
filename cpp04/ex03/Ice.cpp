#include "includes/Ice.hpp"

Ice::Ice() { std::cout << "Ice constructor called" << std::endl; }

Ice::~Ice() { std::cout << "Ice destructor called" << std::endl; }

Ice::Ice(Ice& const cpy) { *this = cpy; }

Ice& Ice::operator=(Ice& const rhs) { return *this; }

const std::string Ice::getType() { return this->_type; }

Ice* Ice::clone() const { return (new Ice()); }

Ice* Ice::createMateria(std::string type) { 
	if (type != "ice")
		return 0;
	AMateria* newMateria = new Ice();
	newMateria->type = this->type;  
	return newMateria;
}

void Ice::use(ICharacter& target) { std::cout << "* shoots an ice bolt at " << target.getName() << std::endl; }