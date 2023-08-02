#include "includes/includes.hpp"

int main()
{
	ICharacter* char1 = new Character("Lee");
	ICharacter* char2 = new Character("Rob");

	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	// Equip/Unequip materia
	std::cout << std::endl;
	char1->equip(new Ice());
	char1->use(0, *char2);
	char1->unequip(0);
	char1->use(0, *char2);
	std::cout << std::endl;

	char1->equip(src->createMateria("ice"));
	char1->equip(src->createMateria("cure"));
	char1->equip(src->createMateria("ice"));
	char1->use(0, *char2);
	char1->use(1, *char2);
	char1->use(2, *char2);

	std::cout << std::endl;
	char1->unequip(1);
	char1->displayUnequippedEquipment();

	// Character index error
	std::cout << std::endl;
	char1->use(3, *char2);
	char1->use(4, *char2);

	delete char1;
	delete char2;
	delete src;
}