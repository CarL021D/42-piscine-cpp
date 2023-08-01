
#pragma once
#include "IAnimal.hpp"
#include "Brain.hpp"

class Cat : public IAnimal {

	public:
			Cat();
			~Cat();
			Cat(const Cat& cpy);
			Cat& operator=(const Cat& rhs);
			
			void makeSound() const;
			void displayIdea(short i) const;
	private:
			Brain	*_brain;};