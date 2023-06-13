
#pragma once
#include <iostream>

class WrongAnimal {

	public:
			WrongAnimal();
			~WrongAnimal();
			WrongAnimal(const WrongAnimal& cpy);
			WrongAnimal& operator=(const WrongAnimal& rhs);
			std::string getType();
			void makeSound() const;

	protected:
			std::string		_type;
};