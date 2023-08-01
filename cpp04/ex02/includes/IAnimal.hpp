
#pragma once
#include <iostream>

class IAnimal {

	public:
			IAnimal();
			virtual ~IAnimal();
			IAnimal(const IAnimal& cpy);
			IAnimal& operator=(const IAnimal& cpy);

			std::string 	getType() const;
			virtual void	makeSound() const = 0;
			virtual void	displayIdea(short i) const { (void)i; };
			virtual void	setNewIdea(short i, std::string new_idea) { (void)i; (void)new_idea; };

	protected:
			std::string		_type;
};