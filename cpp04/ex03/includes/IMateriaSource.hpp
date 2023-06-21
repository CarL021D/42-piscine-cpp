#pragma once
#include "includes.hpp"

class IMAteriaSource {
	public:
			virtual ~IMateriaSource() = default;
			virtual void learnMateria(AMateria*) = 0;
			virtual AMateria* createMateria((std::string const &) = 0;
};