#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {}

~WrongAnimal::WrongAnimal() {}

WrongAnimal::WrongAnimal(const WrongAnimal& rhs) { *this = cpy; }

WrongAnimal& WrongAnimal::operator=(const WroongAnimal& rhs) {
	this->type = rhs.type;
	return *this;
}