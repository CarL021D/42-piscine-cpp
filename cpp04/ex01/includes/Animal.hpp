
#pragma once
#include <iostream>

class Animal {

	public:
			Animal();
			virtual ~Animal();
			Animal(const Animal& cpy);
			Animal& operator=(const Animal& cpy);

			std::string getType() const;
			virtual void makeSound() const;
			virtual void displayIdea(short i) const { (void)i; };
			virtual void setNewIdea(short i, std::string new_idea) { (void)i; (void)new_idea; };

	protected:
			std::string		_type;
};