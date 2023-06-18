#pragma once
#include <iostream>

class Cure : public AMateria {
     public:
            Cure();
			~Cure();
			Cure(Cure& const cpy);
			Cure& operator=(Cure& const rhs);

			Cure(std::string const & type);
			std::string const & getType() const;
			Cure* clone() const = 0;
			void use(ICharacter& target);
    protected:
            std::string     type;
}