
#pragma once
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {

	public:
			Cat();
			~Cat();
			Cat(const Cat& cpy);
			Cat& operator=(const Cat& rhs);
			
			void makeSound() const;
			void displayIdea(short i) const;
	private:
			Brain	*_brain;};