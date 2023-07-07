


#pragma once
#include "includes.hpp"

class MateriaSource : public IMateriaSource {
    public:
            MateriaSource();
			~MateriaSource();
			MateriaSource(std::string name);
			MateriaSource(const MateriaSource& src);
			MateriaSource& operator=(const MateriaSource& rhs);

			void learnMateria(AMateria*);
			AMateria* getMateria(short i) const;
			AMateria* createMateria(const std::string&);
	private:
			AMateria* _inventory[4];
};