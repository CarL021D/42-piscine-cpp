#include "includes/includes.hpp"

Character::Character() {
	std::cout << "Character constructor called" << std::endl;
	for (short i = 0; i < 4; i++)
		this->items[i] = NULL;
	this->_name = "";
}

Character::~Character() { std::cout << "Character destructor called" << std::endl; }

Character::Character(std::string name) : Character(), _name(name) {}

Character::Character(const Character& cpy) { *this = cpy; }

Character& Character::operator=(const Character& rhs) {
	this->_name = rhs->getName()
	for (short i = 0; i < 4; i++;)
		this->_items[i] = rhs->getItems(i);
	this->_unequippedItems = rhs->copyUnequippedItems(rhs);
	return *this;
}

std::string const & getName() const { return this->_name; }

AMateria const getItems(short i) const { return this->_items[i]; }

std::list<AMateria> copyUnequippedItems(std::list<AMateria> sourceList) {
	std::list<AMateria> copyList(sourceList);
	return copyList;
}

void Character::equip(AMateria* m) {	
	for (short i = 0; i < 4; i++)
	{
		if (this->_items[i] == NULL)
		{
			_items[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3 || this->_items[idx] == NULL)
		return;
	this->_unequippedItems.push_back(this->_items[idx]);
	this->items[idx] = NULL;
}

void Character::use(int idx, Character& target) const {
	if (idx < 0 || idx > 3)
		return;
	_items[idx]->use(*this);	
}