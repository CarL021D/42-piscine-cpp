
#include "includes/Includes.hpp"

int main()
{
	// IAnimal animal;

	IAnimal* animalArr[4];

	std::cout << std::endl << "Animal array construction:" << std::endl;
	for (short i = 0; i < 4 ; i++) {
		if (i < 2)
			animalArr[i] = new Dog();
		else
			animalArr[i] = new Cat();
	}

	std::cout << std::endl << "Display Idea:" << std::endl;
	std::cout << animalArr[0]->getType() << std::endl;
	animalArr[0]->displayIdea(4);
	std::cout << std::endl;
	std::cout << animalArr[3]->getType() << std::endl;
	animalArr[3]->displayIdea(100);
	std::cout << std::endl;

	std::cout << "Animal array destruction:" << std::endl;
	for (short i = 0; i < 4 ; i++)
		delete animalArr[i];
	std::cout << std::endl;
}