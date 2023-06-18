#include "includes/includes.hpp"

ICharacter::ICharacter() { std::cout << "ICharacter constructor called" << std::endl; }

ICharacter::~ICharacter() { std::cout << "ICharacter destructor called" << std::endl; }

ICharacter::ICharacter(ICharacter& const cpy) { *this = cpy; }

ICharacter& ICharacter::operator=(ICharacter& const rhs) { return *this; }

void ICharacter::equip(AMateria* m) {
	
}

void ICharacter::unequip(int idx) {
    
}

void ICharacter::use(int idx, ICharacter& target) {

}