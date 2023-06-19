#pragma once
#include "includes.hpp"

class Character : public ICharacter {
	public:
			Character();
			virtual ~Character() {}
			std::string const & getName() const;
			void equip(AMateria* m);
			void unequip(int idx);
			void use(int idx, ICharacter& target) const;
	private:
			virtual std::string			_name;
			virtual std::list<AMateria>	_unequipItems;
			virtual AMateria			_items[4];

}