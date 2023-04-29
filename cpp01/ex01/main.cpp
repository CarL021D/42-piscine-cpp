#include "Zombie.hpp"

int main() {

	Zombie* zombieArr = zombieHorde(4, "Bob");
	for (uint32_t i = 0; i < 4; i++)
		zombieArr[i].announce();
	delete [] zombieArr;
}