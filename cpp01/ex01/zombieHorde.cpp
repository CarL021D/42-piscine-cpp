#include "Zombie.hpp"

Zombie*	zombieHorde(int n, std::string name) {

	Zombie* zombieArr = new Zombie[n];
	for (int32_t i = 0; i < n; i++)
		zombieArr[i].setName(name);
	return zombieArr;
}