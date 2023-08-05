
#include "includes/Includes.hpp"

int main()
{
	Animal* animalArr[4];

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



	// // Copy constructor test
	// Dog *dog1 = new Dog();
	// Dog dog2(*dog1);

	// std::cout << "---" << std::endl;
	// std::cout << "dog1:" << std::endl;
	// dog1->displayIdea(21);
	// std::cout << "dog2:" << std::endl;
	// dog2.displayIdea(21);

	// std::cout << "dog1 new idea:" << std::endl;
	// dog1->setNewIdea(21, "Go Lee");
	// dog1->displayIdea(21);

	// std::cout << "dog2:" << std::endl;
	// dog2.displayIdea(21);
	// std::cout << std::endl;

	// delete dog1;
	// std::cout << std::endl;
	
	// std::cout << "dog2:" << std::endl;
	// dog2.displayIdea(21);

	// // Assignment construcot Test
	// {
	// 	Dog dog0;

	// 	std::cout << std::endl;
	// 	dog0.setNewIdea(21, "Let's create a program");
	// 	dog1 = &dog0;
	// 	std::cout << std::endl;

	// 	std::cout << "dog0:" << std::endl;
	// 	dog0.displayIdea(21);
	// 	std::cout << "dog1:" << std::endl;
	// 	dog1->displayIdea(21);
	// 	std::cout << std::endl;
	// }
}
