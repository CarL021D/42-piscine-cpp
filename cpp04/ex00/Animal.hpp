
#pragma once

#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"

class Animal {

	public:
			Animal();
			~Animal();
			Animal(const Animal& cpy);
			Animal& operator=(const Animal& rhs);
			std::string getType() const;
			virtual void makeSound() const = 0;

	private:
			std::string		type;
};