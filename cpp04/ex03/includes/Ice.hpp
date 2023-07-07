#pragma once
#include "includes.hpp"

class Ice : public AMateria {
	public:
			Ice();
			~Ice();
			Ice(const Ice& src);
			Ice& operator=(const Ice& rhs);

			Ice*	clone() const;
			void	use(ICharacter& target);
	// protected:
	// 		std::string		_type;
};