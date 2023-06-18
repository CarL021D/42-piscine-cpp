#pragma once
#include <iostream>

class Ice : public AMateria {
    public:
            Ice();
			~Ice();
			Ice(Ice& const cpy);
			Ice& operator=(Ice& const rhs);

			Ice(std::string const & type);
			std::string const & getType() const;
			Ice* clone() const = 0;
			void use(ICharacter& target);
}