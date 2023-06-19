#pragma once
#include "includes.hpp"

class ICharacter {
	public:
			ICharacter();
			virtual ~ICharacter();
			ICharacter(std::string name);
			ICharacter(ICharacter& const cpy);
			ICharacter& operator=(ICharacter& const rhs);

			virtual std::string const & getName() const = 0;
			virtual void equip(AMateria* m) = 0;
			virtual void unequip(int idx) = 0;
			virtual void use(int idx, ICharacter& target) = 0;
	private:
			_name;
};