#pragma once
#include "includes.hpp"

class Ice : public AMateria {
	public:
			Ice();
			~Ice();
			Ice(Ice& const cpy);
			Ice& operator=(Ice& const rhs);

			Ice(std::string const & type);
			std::string const & getType() const;
			Ice*	clone() const;
			void	use(ICharacter& target);
			Ice*	createMateria(std::string type)
	protected:
			std::string		_type;
}