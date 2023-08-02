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
			std::cout << m->getType() << " equiped" << std::endl;
			this->_items[i] = m;
			return;
		}
	}
	std::cout << "Not enough space in the inventory" << std::endl;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3 || this->_items[idx] == NULL)
	{
		std::cout << "No Amateria at this index, you can not use it" << std::endl;
		return;
	}

	AMateria** tmp = new AMateria*[this->_unequippedItemsCount +  1];

	std::cout << _items[idx]-> getType() << " unequiped at indedex [" << idx << "]" << std::endl;
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

void Character::displayEquipment() const {
	for (short i = 0; i < 4; i++)
		std::cout << "[" << i << "] " << _items[i]->getType() << std::endl;
	std::cout << std::endl;
}

void Character::displayUnequippedEquipment() const {
	if (!this->_unequippedItemsCount) {
		std::cout << "Nothing was dropped" << std::endl;
		return ;
	}

	std::cout << this->_name << " unquipped item list:" << std::endl;
    for (int i = 0; i < this->_unequippedItemsCount; i++) {
		std::cout	<< "unequipped item " << i << " of type "
					<< this->_unequippedItems[i]->getType() << std::endl;
    }
}