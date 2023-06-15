
#include "includes/Includes.hpp"

int main()
{
	Animal* animalArr[4];

	for (short i = 0; i < 4 ; i++)
	{
		if (i % 2)
			animalArr[i] = new Dog();
		else
			animalArr[i] = new Cat();
	}

	std::cout << std::endl;
	Dog dog();
	Cat cat();
	// TODO: - Display secret info

	std::cout << std::endl << "Class destruction:" << std::endl;
	for (short i = 0; i < 4 ; i++)
		delete animalArr[i];
	return 0;
}