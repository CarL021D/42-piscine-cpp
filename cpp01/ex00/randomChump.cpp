#include "Zombie.hpp"

void randomChump(std::string name) {

	Zombie new_zombie = Zombie();
	new_zombie.setName(name);
	new_zombie.announce();
}