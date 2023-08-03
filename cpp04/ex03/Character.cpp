#include "includes/includes.hpp"

Character::Character() : _name("default name"),  _unequippedItems(NULL), _unequippedItemsCount(0) {
	for (short i = 0; i < 4; i++)
		this->_items[i] = NULL;
}

Character::~Character() {
	for (short i = 0; i < 4; i++)
		if (this->_items[i] != NULL)
			delete _items[i];
	
	if (this->_unequippedItemsCount) {
		for (int i = 0; i < this->_unequippedItemsCount; i++)
			delete this->_unequippedItems[i];
		delete[] this->_unequippedItems;
	}
}

Character::Character(std::string name) : _name(name), _unequippedItems(NULL), _unequippedItemsCount(0) {
	for (short i = 0; i < 4; i++)
		this->_items[i] = NULL;
}

Character::Character(const Character& src) {
	this->_name = src._name;
	for (short i = 0; i < 4; i++)
		this->_items[i] = src._items[i];
	this->_unequippedItems = src._unequippedItems;
	this->_unequippedItemsCount = src._unequippedItemsCount;
	*this = src;
}

Character& Character::operator=(const Character& rhs) {
	std::string	itemsTypeStr[4];
	std::string	unequippedItemsTypeStr[rhs._unequippedItemsCount];

	for (short i = 0; i < 4; i++) {
		if (rhs._items[i] != NULL) {
			itemsTypeStr[i] = rhs._items[i]->getType();
			if (this->_items[i]) {
				delete this->_items[i];
				this->_items[i] = NULL;
			}
		}
		else
			itemsTypeStr[i] = "null";
	}
	
	for (short i = 0; i < 4; i++) {
 		if (itemsTypeStr[i] == "ice")
			this->_items[i] = new Ice();
		else if (itemsTypeStr[i] == "cure")
			this->_items[i] = new Cure();
		else
			this->_items[i] = NULL;
	}

	if (!this->_unequippedItemsCount)
		return *this;

	this->_name = rhs._name;
	this->_unequippedItemsCount = rhs._unequippedItemsCount;

	for (short i = 0; i < this->_unequippedItemsCount; i++)
		unequippedItemsTypeStr[i] = rhs._items[i]->getType();

	this->_unequippedItems = new AMateria*[this->_unequippedItemsCount];

	for (short i = 0; i < this->_unequippedItemsCount; i++) {
		if (unequippedItemsTypeStr[i] == "ice")
			this->_unequippedItems[i] = new Ice();
		else
			this->_unequippedItems[i] = new Cure();
	}
	return *this;
}

std::string const & Character::getName() const { return this->_name; }

AMateria* Character::getItems(short i) const { return this->_items[i]; }

void Character::equip(AMateria* m) {	
	for (short i = 0; i < 4; i++) {
		if (!this->_items[i]) {
			std::cout << m->getType() << " equiped" << std::endl;
			this->_items[i] = m;
			return;
		}
	}
	delete m;
	std::cout << "Not enough space in the inventory" << std::endl;
}

void Character::unequip(int idx) {
	AMateria** tmp;

	if (idx < 0 || idx > 3 || this->_items[idx] == NULL) {
		std::cout << "No Amateria at this index, you can not unequipped it" << std::endl;
		return;
	}

	tmp = new AMateria*[this->_unequippedItemsCount + 1];

	std::cout	<< this->_name << " " << _items[idx]-> getType()
				<< " unequiped at indedex [" << idx << "]" << std::endl;
	
	for (int i = 0; i < this->_unequippedItemsCount; i++)
		tmp[i] = this->_unequippedItems[i];
	
	if (this->_unequippedItems != NULL) {
		delete[] this->_unequippedItems;
		this->_unequippedItems = NULL;
	}
	tmp[this->_unequippedItemsCount] = this->_items[idx];
	this->_items[idx] = NULL;
	this->_unequippedItems = tmp;
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
	std::cout << this->_name << " equipped items list:" << std::endl;
	for (short i = 0; i < 4; i++)
		if (_items[i])
			std::cout << "\t[" << i << "] " << _items[i]->getType() << std::endl;
	std::cout << std::endl;
}

void Character::displayUnequippedEquipment() const {
	if (!this->_unequippedItemsCount) {
		std::cout << "Nothing was dropped" << std::endl;
		return ;
	}

	std::cout << this->_name << " unequipped items list:" << std::endl;



    for (int i = 0; i < this->_unequippedItemsCount; i++) {
		std::cout	<< "\tunequipped item " << i << " -> "
					<< this->_unequippedItems[i]->getType() << std::endl;
    }
}