
#pragma once

#include <iostream>

class Animal {

	public:
			Animal();
			~Animal();
			Animal(const Animal& cpy);
			Animal operator=(const Animal& rhs);
			virtual void makeSound() const = 0;

	private:
			std::string		type;
};