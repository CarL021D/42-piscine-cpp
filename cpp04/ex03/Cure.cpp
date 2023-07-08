#include "includes/Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::~Cure() {}

Cure::Cure(const Cure& src) { *this = src; }

Cure& Cure::operator=(const Cure& rhs) {
	this->_type = rhs._type;
	return *this;
}

Cure* Cure::clone() const {
	Cure* cure = new Cure();
	cure->setType("cure");
	return (cure);
}

void Cure::use(ICharacter& target) { std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl; }