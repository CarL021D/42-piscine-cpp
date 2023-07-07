#pragma once
#include "includes.hpp"

class Character : public ICharacter {
	public:
			Character();
			virtual ~Character();
			Character(std::string name);
			Character(const Character& src);
			Character& operator=(const Character& rhs);

			std::string const & getName() const;
			AMateria* getItems(short i) const;
			std::list<AMateria*> copyUnequippedItems(std::list<AMateria*> sourceList);
			void equip(AMateria* m);
			void unequip(int idx);
			void use(int idx, ICharacter& target);
			virtual void displayUnequippedEquipment() const;

	private:
			std::string				_name;
			std::list<AMateria*>	_unequippedItems;
			AMateria*				_items[4];
};