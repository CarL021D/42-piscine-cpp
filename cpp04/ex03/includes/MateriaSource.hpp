


#pragma once
#include "includes.hpp"

class MateriaSource : public IMateriaSource {
    public:
            MateriaSource();
			~MateriaSource();
			MateriaSource(std::string name);
			MateriaSource(MateriaSource& const cpy);
			MateriaSource& operator=(MateriaSource& const rhs);

			void learnMateria(AMateria*);
			AMateria* createMateria(std::string const&);
	private:
			Materia _inventory[4];
};