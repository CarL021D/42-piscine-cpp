
#pragma once
#include <iostream>

class AAnimal {

	public:
			AAnimal();
			virtual ~AAnimal();
			AAnimal(const AAnimal& cpy);
			AAnimal& operator=(const AAnimal& cpy);

			std::string 	getType() const;
			virtual void	makeSound() const = 0;
			virtual void	displayIdea(short i) const { (void)i; };
			virtual void	setNewIdea(short i, std::string new_idea) { (void)i; (void)new_idea; };

	protected:
			std::string		_type;
};