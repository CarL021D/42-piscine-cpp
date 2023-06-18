





Character::Character() { std::cout << "Character constructor called" << std::endl; }

Character::~Character() { std::cout << "Character destructor called" << std::endl; }

Character::Character(Character& const cpy) { *this = cpy; }

Character& Character::operator=(Character& const rhs) { return *this; }

void Character::equip(AMateria* m) {
	
}

void Character::unequip(int idx) {
    
}

void Character::use(int idx, Character& target) {

}