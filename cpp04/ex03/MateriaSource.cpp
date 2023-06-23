#include "includes/MateriaSource.hpp"

MateriaSource::MateriaSource() {
	std::cout << "MateriaSource constructor called" << std::endl;
	for (short i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

MateriaSource::~MateriaSource() { std::cout << "MateriaSource destructor called" << std::endl; }

MateriaSource::MateriaSource(const MateriaSource& cpy) { *this = cpy; }

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs) {
	for (short i = 0; i < 4; i++)
		this->_inventory[i] = rhs.getMateria(i)->clone();
	return *this;
}

void MateriaSource::learnMateria(AMateria* materia) {
	for (short i = 0; i < 4; i++)
	{
		if (_inventory[i] != NULL)
		{
			_inventory[i] = materia;
			return;
		}
	}
}

AMateria* MateriaSource::getMateria(short i) const { return this->_inventory[i]; }

AMateria* MateriaSource::createMateria(const std::string& type) {
	for (short i = 0; i < 4; i++)
		if (type == _inventory[i]->getType())
			return _inventory[i]->clone();
	return NULL; 
}