include "includes/inlcudes.hpp"

Character::Character() {
	std::cout << "Character constructor called" << std::endl;
	for (short i = 0; i < 4; i++)
		this->items[i] = nullptr;	
}

Character::~Character() { std::cout << "Character destructor called" << std::endl; }

Character::Character(Character& const cpy) { *this = cpy; }

Character& Character::operator=(Character& const rhs) { return *this; }

void Character::equip(AMateria* m) {
	
	for (short i = 0; i < 4; i++)
	{
		if (this->items[i] == nullptr)
		{
			items[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3 || this->items[idx] == nullptr)
		return;
	this->unequipItems.push_back(this->items[idx]);
	this->items[idx] = nullptr;
}

void Character::use(int idx, Character& target) {
	if (idx < 0 || idx > 3)
		return;
	items[idx]->use(*this);
	
}