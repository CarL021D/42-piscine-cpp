#include "includes/includes.hpp"

int main()
{
	ICharacter* ken = new Character("Ken");
	ICharacter* lee = new Character("Lee");


	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ken->equip(src->createMateria("ice"));
	ken->equip(src->createMateria("cure"));
	ken->equip(src->getMateria(0));
	ken->equip(src->getMateria(1));

	std::cout << std::endl;
	ken->use(1, *lee);
	// me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	// ICharacter* bob = new Character("bob");
	// me->use(0, *bob);
	// me->use(1, *bob);
	// delete bob;
	// delete me;
	// delete src;
	// return 0;
}