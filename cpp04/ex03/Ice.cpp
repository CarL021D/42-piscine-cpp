#include "includes/Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::~Ice() {}

Ice::Ice(const Ice& src) { *this = src; }

Ice& Ice::operator=(const Ice& rhs) {
	this->_type = rhs.getType();
	return *this;
}

Ice* Ice::clone() const { 
	Ice* ice = new Ice();
	ice->setType("ice");
	return (ice);
}

void Ice::use(ICharacter& target) { std::cout << "* shoots an ice bolt at " << target.getName() << std::endl; }