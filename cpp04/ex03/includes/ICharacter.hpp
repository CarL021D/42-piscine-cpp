#pragma once
#include "includes.hpp"

class ICharacter {
	public:
			virtual ~ICharacter() {}
			virtual std::string const & getName() const = 0;
			virtual void equip(AMateria* m) = 0;
			virtual void unequip(int idx) = 0;
			virtual void use(int idx, ICharacter& target) = 0;
	protected:
			virtual std::string		name;
			virtual AMateria		items[4];
};