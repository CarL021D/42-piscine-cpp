
#include "includes/Includes.hpp"

int main()
{
	Animal* animalArr[4];

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
	Dog dog;
	Cat cat;

	std::cout << std::endl << "Display Idea" << std::endl;
	dog.displayIdea(4);
	cat.displayIdea(100);
	std::cout << std::endl;
	
	return 0;
}