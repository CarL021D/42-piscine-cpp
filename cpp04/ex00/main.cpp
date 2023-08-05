
#include "includes/Includes.hpp"

int main()
{
	Animal* meta = new Animal();
	Animal* dog = new Dog();
	Animal* cat = new Cat();

	std::cout << std::endl << "Aniamls type:" << std::endl;
	std::cout << "\t" << meta->getType() << " " << std::endl;
	std::cout << "\t" << dog->getType() << " " << std::endl;
	std::cout << "\t" << cat->getType() << " " << std::endl;
	std::cout << std::endl;

	std::cout << std::endl << "Animals sound:" << std::endl;
	meta->makeSound();
	dog->makeSound();
	cat->makeSound();
	std::cout << std::endl;

	delete meta;
	delete dog;
	delete cat;
	
	std::cout << std::endl << std::endl;

	
	WrongAnimal* wrongMeta = new WrongCat();
	WrongCat* wrongCat = new WrongCat();

	std::cout << std::endl;
	std::cout << wrongMeta->getType() << " " << std::endl;
	std::cout << wrongCat->getType() << " " << std::endl;
	std::cout << std::endl;

	std::cout << std::endl << "Wrong animals sound:" << std::endl;
	wrongMeta->makeSound();
	wrongCat->makeSound();
	std::cout << std::endl;
	
	delete wrongMeta;
	delete wrongCat;
}