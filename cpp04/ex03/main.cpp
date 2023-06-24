#include "includes/includes.hpp"

int main()
{
	ICharacter* ken = new Character("Ken");
	ICharacter* lee = new Character("Lee");

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << std::endl;
	ken->equip(new Ice());
	ken->use(0, *lee);
	ken->unequip(0);
	ken->use(0, *lee);

	std::cout << std::endl;
	ken->equip(src->createMateria("cure"));
	ken->use(0, *lee);



	// me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	// ICharacter* bob = new Character("bob");
	// me->use(0, *bob);
	// me->use(1, *bob);
	// delete bob;
	
	std::cout << std::endl << "Class destruction!" << std::endl;
	delete ken;
	delete lee;
	// return 0;
}