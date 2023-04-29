#pragma once
#include <iostream>
#include <stdint.h>


class Zombie {

	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();

		void    setName(std::string name);
		void	announce();

	private:
		std::string     _name;
};

Zombie*	zombieHorde(int n, std::string name);
