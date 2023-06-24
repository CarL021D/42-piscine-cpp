#include "includes/Ice.hpp"

Ice::Ice() { this->_type = "ice"; }

Ice::~Ice() {}

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

Ice* Ice::clone() const { 
	Ice* ice = new Ice();
	ice->setType("ice");
	return (ice);
}

void Ice::use(ICharacter& target) { std::cout << "* shoots an ice bolt at " << target.getName() << std::endl; }