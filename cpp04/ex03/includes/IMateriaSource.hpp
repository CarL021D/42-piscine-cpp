#pragma once
#include "includes.hpp"

class IMateriaSource {
	public:
			virtual ~IMateriaSource() {}
			virtual void learnMateria(AMateria*) = 0;
			virtual AMateria* createMateria(std::string const &) = 0;
			virtual AMateria* getMateria(short i) const = 0;
};