
#pragma once
#include <iostream>

class WrongAnimal {

	public:
			WrongAnimal();
			~WrongAnimal();
			WrongAnimal(const WrongAnimal& cpy);
			WrongAnimal& operator=(const WrongAnimal& rhs);

			void makeSound() const;
			std::string getType();
	protected:
			std::string		_type;
};