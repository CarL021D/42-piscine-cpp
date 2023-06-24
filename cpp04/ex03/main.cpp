#include "includes/includes.hpp"

int main()
{
	AMateria* ice = new Ice();
	std::cout << "<<" << ice->getType() << std::endl;
}

// int main()
// {
// 	// ICharacter* ken = new Character("Ken");
// 	// ICharacter* lee = new Character("Lee");

// 	// IMateriaSource* src = new MateriaSource();

// 	AMateria* ice = new Ice();
// 	std::cout << "<<" << ice->getType() << std::endl;

// 	// src->learnMateria(new Ice());
// 	// src->learnMateria(new Cure());

// 	// // std::cout << std::endl;
// 	// // ken->equip(new Ice());
// 	// // ken->use(0, *lee);
// 	// // ken->unequip(0);
// 	// // ken->use(0, *lee);

// 	// std::cout << std::endl;
// 	// ken->equip(src->createMateria("ice"));
// 	// ken->equip(src->createMateria("cure"));
// 	// ken->use(0, *lee);
// }