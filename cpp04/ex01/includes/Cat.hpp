
#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {

	public:
			Cat();
			~Cat();
			Cat(const Cat& cpy);
			Cat& operator=(const Cat& rhs);
			
			void makeSound() const;
			void displayIdea(short i) const;
	private:
			Brain	*_brain;
};