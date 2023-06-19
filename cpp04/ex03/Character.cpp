include "includes/inlcudes.hpp"

Character::Character() {
	std::cout << "Character constructor called" << std::endl;
	for (short i = 0; i < 4; i++)
		this->items[i] = nullptr;
	this->_name = "";
}

Character::~Character() { std::cout << "Character destructor called" << std::endl; }

Character::Character(std::string name) : Character(), _name(name) {}

Character::Character(Character& const cpy) { *this = cpy; }

Character& Character::operator=(Character& const rhs) { return *this; }

std::string const & getName() const { return this->_name}

void Character::equip(AMateria* m) {
	
	for (short i = 0; i < 4; i++)
	{
		if (this->_items[i] == nullptr)
		{
			_items[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3 || this->_items[idx] == nullptr)
		return;
	this->_unequipItems.push_back(this->_items[idx]);
	this->items[idx] = nullptr;
}

void Character::use(int idx, Character& target) const {
	if (idx < 0 || idx > 3)
		return;
	_items[idx]->use(*this);	
}