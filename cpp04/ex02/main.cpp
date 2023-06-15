
#include "includes/Includes.hpp"

int main()
{
	IAnimal* animalArr[4];

	std::cout << std::endl << "Animal array construction:" << std::endl;
	for (short i = 0; i < 4 ; i++)
	{
		if (i < 2)
			animalArr[i] = new Dog();
		else
			animalArr[i] = new Cat();
	}

	std::cout << std::endl << "Animal array destruction:" << std::endl;
	for (short i = 0; i < 4 ; i++)
		delete animalArr[i];

	std::cout << std::endl;
	Dog *dog = new Dog();
	Cat *cat = new Cat();

	std::cout << std::endl << "Display Idea" << std::endl;
	std::cout << dog->getType() << std::endl;
	dog->displayIdea(4);
	std::cout << cat->getType() << std::endl;
	cat->displayIdea(100);
	std::cout << std::endl;

	delete dog;
	delete cat;

	return 0;
}