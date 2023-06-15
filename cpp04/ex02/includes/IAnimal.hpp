
#pragma once
#include <iostream>

class IAnimal {

	public:
			IAnimal();
			virtual ~IAnimal();
			IAnimal(const IAnimal& cpy);
			IAnimal& operator=(const IAnimal& cpy);
			virtual std::string		getType() const = 0;
			virtual void			makeSound() const = 0;

	protected:
			std::string		_type;
};