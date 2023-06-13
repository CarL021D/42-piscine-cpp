
#pragma once
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

	public:
			WrongCat();
			~WrongCat();
			WrongCat(const WrongCat& cpy);
			WrongCat& operator=(const WrongCat& rhs);
			void makeSound() const;
};