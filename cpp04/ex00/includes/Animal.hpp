
#pragma once
#include <iostream>

class Animal {

	public:
			Animal();
			virtual ~Animal();
			Animal(const Animal& cpy);
			Animal& operator=(const Animal& rhs);
			std::string getType() const;

			virtual void makeSound() const;
	protected:
			std::string		_type;
};