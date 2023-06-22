#include "includes/includes.hpp"

Character::Character() {
	std::cout << "Character constructor called" << std::endl;
	for (short i = 0; i < 4; i++)
		this->_items[i] = NULL;
	this->_name = "";
}

Character::~Character() { std::cout << "Character destructor called" << std::endl; }

Character::Character(std::string name) : _name(name) {}

Character::Character(const Character& cpy) { *this = cpy; }

Character& Character::operator=(const Character& rhs) {
	// this->_name = rhs.getName();
	// for (short i = 0; i < 4; i++)
	// 	this->_items[i] = rhs.getItems(i);
	// this->_unequippedItems = rhs.copyUnequippedItems(rhs._unequippedItems);
	

	this->_name = rhs.getName();
	for (short i = 0; i < 4; i++)
	{
		if (this->_items[i])
			this->_items[i] = rhs.getItems(i)->clone();
	}
	// for (short i = 0; i < 4; i++)
	// 	this->_items[i] = rhs.getItems(i);
	// this->_unequippedItems = rhs.copyUnequippedItems(rhs._unequippedItems);
	return *this;


	return *this;
}

std::string const & Character::getName() const { return this->_name; }

AMateria* Character::getItems(short i) const { return this->_items[i]; }

std::list<AMateria*> Character::copyUnequippedItems(std::list<AMateria*> sourceList) {
	std::list<AMateria*> copyList(sourceList);
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
	this->_items[idx] = NULL;
}

void Character::use(int idx, Character& target) const {
	if (idx < 0 || idx > 3)
		return;
	this->_items[idx]->use(target);	
}