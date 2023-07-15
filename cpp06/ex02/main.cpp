
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "includes/Base.hpp"

void identify(Base& p) {
	try {
		A&	aClass = dynamic_cast<A&>(p);
		(void)aClass;
		std::cout << "A class identified" << std::endl;
	} catch (const std::bad_cast& e) {
		try {
				B&	bClass = dynamic_cast<B&>(p);
				(void)bClass;
				std::cout << "B class identified" << std::endl;
		} catch (const std::bad_cast& e) {
			try {
				C&	cClass = dynamic_cast<C&>(p);
				(void)cClass;
				std::cout << "C class identified" << std::endl;
			} catch (const std::bad_cast& e) {
				std::cerr << "Failed to indentify anything: " << e.what() << std::endl;
			}
		}
	}
}

void identify(Base* p) {

	A*	aClass = dynamic_cast<A*>(p);
	if (aClass != NULL) {
		(void)aClass;
		std::cout << "A class identified" << std::endl;
		return ;
	} else {
		B*	bClass = dynamic_cast<B*>(p);
		if (bClass != NULL) {
			(void)bClass;
			std::cout << "B class identified" << std::endl;
			return ;
		} else {
			C*	cClass = dynamic_cast<C*>(p);
			if (cClass != NULL) {
				(void)cClass;
				std::cout << "C class identified" << std::endl;
			}	
		}
	}
}

Base* generate() {
	std::srand(std::time(0));
	int randomNumber = std::rand() % 3;

	if (!randomNumber)
	{
		std::cout << "A class createad" << std::endl;
		return new A();
	} else if (randomNumber == 1) {
		std::cout << "B class createad" << std::endl;
		return new B(); 
	} else {
		std::cout << "C class createad" << std::endl;
		return new C(); 
	}
}

int main() {
	Base* obj = generate();
	identify(obj);
	identify(*obj);
	delete obj;
}