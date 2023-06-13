
#pragma once

#include <iostream>

class WrongAnimal {

	public:
			WrongAnimal();
			~WrongAnimal();
			WrongAnimal(const WrongAnimal& cpy);
			WrongAnimal operator=(const WrongAnimal& rhs);
	private:
			std::string		type;
}