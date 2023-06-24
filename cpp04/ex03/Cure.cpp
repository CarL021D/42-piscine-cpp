#include "includes/Cure.hpp"

Cure::Cure() { this->_type = "cure"; }

Cure::~Cure() {}

Cure::Cure(const Cure& cpy) { *this = cpy; }

Cure::Cure(const std::string& type) {
	if (type != "cure")
	{
		std::cout << "Wrong type name, must be called cure" << std::endl;
		return;
	}
	_type = type;
}

Cure& Cure::operator=(const Cure& rhs) {
	this->_type = rhs.getType();
	return *this;
}

Cure* Cure::clone() const {
	Cure* cure = new Cure();
	cure->setType("cure");
	return (cure);
}

void Cure::use(ICharacter& target) { std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl; }