#include "includes/Ice.hpp"

Ice::Ice() { std::cout << "Ice constructor called" << std::endl; }

Ice::~Ice() { std::cout << "Ice destructor called" << std::endl; }

Ice::Ice(const Ice& cpy) { *this = cpy; }

Ice::Ice(const std::string& type) {
	if (type != "ice")
	{
		std::cout << "Wrong type name, must be called ice" << std::endl;
		return;
	}
	_type = type;
}


Ice& Ice::operator=(const Ice& rhs) {
	this->_type = rhs.getType();
	return *this;
}

std::string const & Ice::getType() const { return this->_type; }

Ice* Ice::clone() const { return (new Ice()); }

Ice* Ice::createMateria(std::string type) { 
	if (type != "ice")
		return 0;
	Ice* newMateria = new Ice("ice");
	// newMateria->type = this->_type;  
	return newMateria;
}

void Ice::use(ICharacter& target) { std::cout << "* shoots an ice bolt at " << target.getName() << std::endl; }