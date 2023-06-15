#pragma once
#include "IAnimal.hpp"
#include "Brain.hpp"

class Dog : public IAnimal {

	public:
			Dog();
			~Dog();
			Dog(const Dog& cpy);
			Dog& operator=(const Dog& rhs);
			void makeSound() const;
			virtual std::string	getType() const;
			void				displayIdea(short i) const;
	private:
			Brain	*brain;
};
