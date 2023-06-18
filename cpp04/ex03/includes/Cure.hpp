#pragma once
#include "includes.hpp"

class Cure : public AMateria {
     public:
            Cure();
			~Cure();
			Cure(Cure& const cpy);
			Cure& operator=(Cure& const rhs);

			Cure(std::string const & type);
			std::string const & getType() const;
			Cure*	clone() const;
			void	use(ICharacter& target);
			Cure*	createMateria(std::string type)
    protected:
            std::string     _type;
}