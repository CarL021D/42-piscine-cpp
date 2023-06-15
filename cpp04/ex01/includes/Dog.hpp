#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {

	public:
			Dog();
			~Dog();
			Dog(const Dog& cpy);
			Dog& operator=(const Dog& rhs);
			void makeSound() const;
			void displayIdea(short i) const;
	private:
			Brain	*brain;
};
