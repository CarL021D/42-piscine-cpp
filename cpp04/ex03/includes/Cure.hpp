#pragma once
#include "includes.hpp"

class Cure : public AMateria {
     public:
            Cure();
			~Cure();
			Cure(const Cure& cpy);
			Cure& operator=(const Cure& rhs);

			Cure(const std::string& type);
			std::string const & getType() const;
			Cure*	clone() const;
			void	use(ICharacter& target);
			Cure*	createMateria(std::string type);
    protected:
            std::string     _type;
};