#include "includes/Cure.hpp"

Cure::Cure() { std::cout << "Cure constructor called" << std::endl; }

Cure::~Cure() { std::cout << "Cure destructor called" << std::endl; }

Cure::Cure(Cure& const cpy) { *this = cpy; }

Cure& Cure::operator=(Cure& const rhs) { return *this; }


const std::string Cure::getType() { return this->type; }

Cure* Cure::clone() const { return (new Cure()); }

Cure* Cure::createMateria(std::string type) {
	if (type != "cure")
		return 0;
	AMateria* newMateria = new Cure();
	newMateria->type = this->type;  
	return newMateria;
}

void Cure::use(ICharacter& target) { std::cout << "* heals " << target.name << "'s wounds *" << std::endl; }