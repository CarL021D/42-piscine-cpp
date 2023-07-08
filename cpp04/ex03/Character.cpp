#include "includes/includes.hpp"

Character::Character() : _name("default name") {
	for (short i = 0; i < 4; i++)
		this->_items[i] = NULL;
	this->_name = "";
}

Character::~Character() {
	for (short i = 0; i < 4; i++)
		if (this->_items[i])
			delete _items[i];
	_unequippedItems.clear();
}

Character::Character(std::string name) : _name(name) {
	for (short i = 0; i < 4; i++)
		this->_items[i] = NULL;
}

Character::Character(const Character& src) { *this = src; }

Character& Character::operator=(const Character& rhs) {
	// this->_name = rhs.getName();
	// for (short i = 0; i < 4; i++)
	// 	this->_items[i] = rhs.getItems(i);
	// this->_unequippedItems = rhs.copyUnequippedItems(rhs._unequippedItems);
	

	this->_name = rhs._name;
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
		if (!this->_items[i])
		{
			this->_items[i] = m;
			return;
		}
	}
	std::cout << "Not enough space in the inventory" << std::endl;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3 || this->_items[idx] == NULL)
		return;
	this->_unequippedItems.push_back(this->_items[idx]);
	this->_items[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3)
		std::cout << "Item usage failed" << std::endl;
	else if (!_items[idx])
		std::cout << "Error, empty index" << std::endl; 
	else
		this->_items[idx]->use(target);	
}

void Character::displayUnequippedEquipment() const {
	std::list<AMateria*>::const_iterator it;
    for (it = _unequippedItems.begin(); it != _unequippedItems.end(); ++it) {
        AMateria* item = *it;
        std::cout << item->getType() << std::endl;
    }
}