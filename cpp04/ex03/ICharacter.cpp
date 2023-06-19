#include "includes/includes.hpp"

ICharacter::ICharacter() { std::cout << "ICharacter constructor called" << std::endl; }

ICharacter::~ICharacter() { std::cout << "ICharacter destructor called" << std::endl; }

ICharacter::ICharacter(std::string name) : ICharacter(), _name(name) {}

ICharacter::ICharacter(const ICharacter& cpy) { *this = cpy; }

ICharacter& ICharacter::operator=(const ICharacter& rhs) { return *this; }

std::string const & ICharacter::getName() const { return this->_name; }

void ICharacter::equip(AMateria* m) {}

void ICharacter::unequip(int idx) {}

void ICharacter::use(int idx, ICharacter& target) {}