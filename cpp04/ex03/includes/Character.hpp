#pragma once
#include "includes.hpp"

class Character : public ICharacter {
	public:
			Character();
			virtual ~Character();
			Character(std::string name);
			Character(Character& const cpy);
			Character& operator=(Character& const rhs);
			
			std::string const & getName() const;
			void equip(AMateria* m);
			void unequip(int idx);
			void use(int idx, ICharacter& target) const;
	private:
			virtual std::string			_name;
			virtual std::list<AMateria>	_unequipItems;
			virtual AMateria			_items[4];

}