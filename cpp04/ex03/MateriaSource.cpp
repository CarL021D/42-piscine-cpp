#include "includes/MateriaSource.hpp"

MateriaSource::MateriaSource() {
	std::cout << "MateriaSource constructor called" << std::endl;
	for (short i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

MateriaSource::~MateriaSource() { std::cout << "MateriaSource destructor called" << std::endl; }

MateriaSource::MateriaSource(MateriaSource& const cpy) { *this = cpy; }

MateriaSource& MateriaSource::operator=(MateriaSource& const rhs) { return *this; }

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

Materia* MateriaSource::createMateria(std::string& const type) {
	for (short i = 0; i < 4; i++)
		if (type == _inventory[i]->getType();)
			return _inventory[i].clone();
	return NULL; 
}