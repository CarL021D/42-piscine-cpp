#include "includes/includes.hpp"

Character::Character() : _name("default name"), _unequippedItemsCount(0) {
	for (short i = 0; i < 4; i++)
		this->_items[i] = NULL;
}

Character::~Character() {
	for (short i = 0; i < 4; i++)
		if (this->_items[i])
			delete _items[i];
	if (this->_unequippedItemsCount) {
		for (int i = 0; i < this->_unequippedItemsCount; i++)
			delete this->_unequippedItems[i];
		delete this->_unequippedItems;
	}
}

Character::Character(std::string name) : _name(name), _unequippedItemsCount(0) {
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
	for (short i = 0; i < 4; i++) {
		if (!this->_items[i]) {
			this->_items[i] = m;
			return;
		}
	}
	std::cout << "Not enough space in the inventory" << std::endl;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3 || this->_items[idx] == NULL)
		return;

	AMateria** tmp = new AMateria*[this->_unequippedItemsCount +  1];

	for (int i = 0; i < this->_unequippedItemsCount; i++)
		tmp[i] = this->_unequippedItems[i];
	delete[] this->_unequippedItems;
	tmp[this->_unequippedItemsCount] = this->_items[idx];
	this->_items[idx] = NULL;
	this->_unequippedItems = tmp;
	tmp = NULL;
	this->_unequippedItemsCount++;
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
	if (!this->_unequippedItemsCount) {
		std::cout << "Nothing was dropped" << std::endl;
		return ;
	}

	std::cout << this->_unequippedItemsCount << std::endl << std::endl;

	std::cout << this->_name << ":" << std::endl;
    for (int i = 0; i < this->_unequippedItemsCount; i++) {
		std::cout	<< "Unequipped item " << i << " of type "
					<< this->_unequippedItems[i]->getType() << std::endl;
    }
}