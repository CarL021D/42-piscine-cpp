#pragma once
#include "includes.hpp"

class Cure : public AMateria {
	 public:
			Cure();
			~Cure();
			Cure(const Cure& src);
			Cure& operator=(const Cure& rhs);

			Cure*	clone() const;
			void	use(ICharacter& target);
	protected:
			std::string	_type;
};