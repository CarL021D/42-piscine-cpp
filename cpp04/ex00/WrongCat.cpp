#include "includes/WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << "WrongCat constructor called" << std::endl;
	this->_type = "WrongCat";
}

WrongCat::~WrongCat() { std::cout << "WrongCat destructor called" << std::endl; }

WrongCat::WrongCat(const WrongCat& cpy) { *this = cpy; }

WrongCat& WrongCat::operator=(const WrongCat& rhs ) {
	this->_type = rhs._type;
	return *this;
}

void	 WrongCat::makeSound() const { std::cout << "Meowww" << std::endl; }