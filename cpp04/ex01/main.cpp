
#include "includes/Includes.hpp"

int main()
{
	// Animal* animalArr[4];

	// std::cout << std::endl << "Animal array construction:" << std::endl;
	// for (short i = 0; i < 4 ; i++) {
	// 	if (i < 2)
	// 		animalArr[i] = new Dog();
	// 	else
	// 		animalArr[i] = new Cat();
	// }

	// std::cout << std::endl << "Display Idea:" << std::endl;
	// std::cout << animalArr[0]->getType() << std::endl;
	// animalArr[0]->displayIdea(4);
	// std::cout << std::endl;
	// std::cout << animalArr[3]->getType() << std::endl;
	// animalArr[3]->displayIdea(100);
	// std::cout << std::endl;

	// std::cout << "Animal array destruction:" << std::endl;
	// for (short i = 0; i < 4 ; i++)
	// 	delete animalArr[i];
	// std::cout << std::endl << std::endl;


	// Shallow copy 
	Dog *dog1 = new Dog();
	dog1->setNewIdea(21, "Nerf Jp");
	Dog dog2(*dog1);
	std::cout << "---" << std::endl;
	dog1->displayIdea(21);
	dog2.displayIdea(21);
	std::cout << std::endl;
	delete dog1;
	std::cout << std::endl;
	dog2.displayIdea(21);
	// {
	// 	Dog dog0;

	// 	std::cout << std::endl;
	// 	dog0.setNewIdea(21, "Let's create a program");
	// 	dog1 = dog0;
	// 	dog0.displayIdea(21);
	// 	dog1.displayIdea(21);
	// 	std::cout << std::endl;
	// }

	// dg1(dog1);
}